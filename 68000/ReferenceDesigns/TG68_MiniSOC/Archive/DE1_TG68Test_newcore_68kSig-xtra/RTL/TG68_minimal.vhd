------------------------------------------------------------------------------
------------------------------------------------------------------------------
--                                                                          --
-- This is the TOP-Level for TG68_fast to generate 68K Bus signals          --
--                                                                          --
-- Copyright (c) 2007-2008 Tobias Gubener <tobiflex@opencores.org>          -- 
--                                                                          --
-- This source file is free software: you can redistribute it and/or modify --
-- it under the terms of the GNU Lesser General Public License as published --
-- by the Free Software Foundation, either version 3 of the License, or     --
-- (at your option) any later version.                                      --
--                                                                          --
-- This source file is distributed in the hope that it will be useful,      --
-- but WITHOUT ANY WARRANTY; without even the implied warranty of           --
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            --
-- GNU General Public License for more details.                             --
--                                                                          --
-- You should have received a copy of the GNU General Public License        --
-- along with this program.  If not, see <http://www.gnu.org/licenses/>.    --
--                                                                          --
------------------------------------------------------------------------------
------------------------------------------------------------------------------
--
-- AMR 2012/04/28: UDS and LDS were not being passed through in some situations
-- Problem seems to have been related to clkena / enaRDreg / enaWRreg
-- Massively simplified the wrapper for standalone usage, eliminated enaRD/WR,
-- Integrated newer, 68020-capable core.
--
-- Revision 1.02 2008/01/23
-- bugfix Timing
--
-- Revision 1.01 2007/11/28
-- add MOVEP
-- Bugfix Interrupt in MOVEQ
--
-- Revision 1.0 2007/11/05
-- Clean up code and first release
--
-- known bugs/todo:
-- Add CHK INSTRUCTION
-- full decode ILLEGAL INSTRUCTIONS
-- Add FDC Output
-- add odd Address test
-- add TRACE
-- Movem with regmask==x0000



library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity TG68 is
   port(        
		clk           : in std_logic;
		reset         : in std_logic;
		clkena_in     : in std_logic:='1';
		data_in       : in std_logic_vector(15 downto 0);
		IPL           : in std_logic_vector(2 downto 0):="111";
		dtack         : in std_logic;
		addr          : out std_logic_vector(31 downto 0);
		data_out      : out std_logic_vector(15 downto 0);
		as            : out std_logic;
		uds           : out std_logic;
		lds           : out std_logic;
		rw            : out std_logic;
		drive_data    : out std_logic;       --enable for data_out driver
		enaRDreg     : in std_logic:='1';
		enaWRreg     : in std_logic:='1'
	);
end TG68;

ARCHITECTURE logic OF TG68 IS
   SIGNAL as_s        : std_logic;
   SIGNAL as_e        : std_logic;
   SIGNAL uds_s       : std_logic;
   SIGNAL uds_e       : std_logic;
   SIGNAL lds_s       : std_logic;
   SIGNAL lds_e       : std_logic;
   SIGNAL rw_s        : std_logic;
   SIGNAL rw_e        : std_logic;
   SIGNAL waitm       : std_logic;
   SIGNAL clkena_e    : std_logic;
   SIGNAL S_state     : std_logic_vector(1 downto 0);
   SIGNAL decode	  : std_logic;
   SIGNAL wr	      : std_logic;
   SIGNAL uds_in	  : std_logic;
   SIGNAL lds_in	  : std_logic;
   SIGNAL state       : std_logic_vector(1 downto 0);
   SIGNAL clkena	  : std_logic;
   SIGNAL cpuIPL      : std_logic_vector(2 downto 0);
	SIGNAL cpuready	: std_logic;
BEGIN  


TG68_inst: entity work.TG68KdotC_Kernel
	generic map (
		SR_Read => 1,				--0=>user,   1=>privileged,      2=>switchable with CPU(0)
		VBR_Stackframe => 1,		--0=>no,     1=>yes/extended,    2=>switchable with CPU(0)
		extAddr_Mode => 1,			--0=>no,     1=>yes,    2=>switchable with CPU(1)
		MUL_Mode => 1,				--0=>16Bit,  1=>32Bit,  2=>switchable with CPU(1),  3=>no MUL,  
		DIV_Mode => 1,			   --0=>16Bit,  1=>32Bit,  2=>switchable with CPU(1),  3=>no DIV,  
		BitField => 1 			   --0=>no,     1=>yes,    2=>switchable with CPU(1)
	)
	PORT MAP (
		clk => clk, 			-- : in std_logic;
		nReset => reset, 		-- : in std_logic;
		clkena_in => clkena, 	-- : in std_logic;
		data_in => data_in, 	-- : in std_logic_vector(15 downto 0);
		IPL => IPL, 			-- : in std_logic_vector(2 downto 0);
		IPL_autovector => '0', 		-- : in std_logic;
		addr => addr, 		-- : out std_logic_vector(31 downto 0);
		data_write => data_out, -- : out std_logic_vector(15 downto 0);
		busstate => state, 	-- : out std_logic_vector(1 downto 0);
		nWr => wr, 				-- : out std_logic;
		nUDS => uds_in, 			-- : out std_logic;
		nLDS => lds_in, 			-- : out std_logic;
		nResetOut => cpuready,
		cpu => "11"
	);
						
	PROCESS (clk, reset, state, as_s, as_e, rw_s, rw_e, uds_s, uds_e, lds_s, lds_e)
		BEGIN
			IF state="01" or cpuready='0' THEN 
				as <= '1';
				rw <= '1';
				uds <= '1';
				lds <= '1';
				clkena <= '1';
			ELSE
				as <= as_s;-- AND as_e;
				rw <= rw_s;-- AND rw_e;
				if wr='0' then -- read cycle...
					uds <= uds_s;
					lds <= lds_s;
				else	-- write cycle...
					uds <= uds_in;
					lds <= lds_in;
				end if;
				clkena <= clkena_in and clkena_e;
			END IF;
	END PROCESS;

	PROCESS (clk, reset, state, as_s, as_e, rw_s, rw_e, uds_s, uds_e, lds_s, lds_e)
		BEGIN
			IF reset='0' THEN
				S_state <= "11";
				as_s <= '1';
				rw_s <= '1';
				uds_s <= '1';
				lds_s <= '1';
			ELSIF rising_edge(clk) THEN
				IF clkena_in='1' and state/="01" then
					as_s <= '1';
					rw_s <= '1';
					uds_s <= '1';
					lds_s <= '1';
					drive_data <= '0';
					clkena_e <= '0';
					CASE S_state IS
						WHEN "00" => as_s <= '0';
							rw_s <= wr;
							IF wr='1' THEN	-- read cycle, assert DS 1 cycle earlier...
								 uds_s <= '0';
								 lds_s <= '0';
							END IF;
							S_state <= "01";
						WHEN "01" => as_s <= '0';
							rw_s <= wr;
							drive_data <= not wr;
							uds_s <= uds_in;
							lds_s <= lds_in;
							S_state <= "10";
						WHEN "10" =>
							uds_s <= uds_in;
							lds_s <= lds_in;
							rw_s <= wr;
							cpuIPL <= IPL;
							drive_data <= NOT wr;
							IF dtack='0' THEN
								S_state <= "11";
								clkena_e<='1';
							END IF;
						WHEN "11" =>
							S_state <= "00";
						WHEN OTHERS => null;			
					END CASE;
				END IF;
			END IF;	
	END PROCESS;
END;	
