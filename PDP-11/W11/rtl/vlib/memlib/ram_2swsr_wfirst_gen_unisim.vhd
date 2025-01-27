-- $Id: ram_2swsr_wfirst_gen_unisim.vhd 314 2010-07-09 17:38:41Z mueller $
--
-- Copyright 2008- by Walter F.J. Mueller <W.F.J.Mueller@gsi.de>
--
-- This program is free software; you may redistribute and/or modify it under
-- the terms of the GNU General Public License as published by the Free
-- Software Foundation, either version 2, or at your option any later version.
--
-- This program is distributed in the hope that it will be useful, but
-- WITHOUT ANY WARRANTY, without even the implied warranty of MERCHANTABILITY
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
-- for complete details.
--
------------------------------------------------------------------------------
-- Module Name:    ram_2swsr_wfirst_gen - syn
-- Description:    Dual-Port RAM with with two synchronous read/write ports
--                 and 'read-through' semantics (as block RAM).
--                 Direct instantiation of Xilinx UNISIM primitives
--
-- Dependencies:   -
-- Test bench:     -
-- Target Devices: Spartan-3, Virtex-2,-4
-- Tool versions:  xst 8.1, 8.2, 9.1, 9.2; ghdl 0.18-0.25
-- Revision History: 
-- Date         Rev Version  Comment
-- 2008-03-08   123   1.1    use now ram_2swsr_xfirst_gen_unisim
-- 2008-03-02   122   1.0    Initial version 
------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

library unisim;
use unisim.vcomponents.ALL;

use work.slvtypes.all;
use work.memlib.all;

entity ram_2swsr_wfirst_gen is          -- RAM, 2 sync r/w ports, write first
  generic (
    AWIDTH : positive := 11;            -- address port width
    DWIDTH : positive :=  9);           -- data port width
  port(
    CLKA  : in slbit;                   -- clock port A
    CLKB  : in slbit;                   -- clock port B
    ENA   : in slbit;                   -- enable port A
    ENB   : in slbit;                   -- enable port B
    WEA   : in slbit;                   -- write enable port A
    WEB   : in slbit;                   -- write enable port B
    ADDRA : in slv(AWIDTH-1 downto 0);  -- address port A
    ADDRB : in slv(AWIDTH-1 downto 0);  -- address port B
    DIA   : in slv(DWIDTH-1 downto 0);  -- data in port A
    DIB   : in slv(DWIDTH-1 downto 0);  -- data in port B
    DOA   : out slv(DWIDTH-1 downto 0); -- data out port A
    DOB   : out slv(DWIDTH-1 downto 0)  -- data out port B
  );
end ram_2swsr_wfirst_gen;


architecture syn of ram_2swsr_wfirst_gen is
begin
  
  UMEM: ram_2swsr_xfirst_gen_unisim
    generic map (
      AWIDTH     => AWIDTH,
      DWIDTH     => DWIDTH,
      WRITE_MODE => "WRITE_FIRST")
    port map (
      CLKA  => CLKA,
      CLKB  => CLKB,
      ENA   => ENA,
      ENB   => ENB,
      WEA   => WEA,
      WEB   => WEB,
      ADDRA => ADDRA,
      ADDRB => ADDRB,
      DIA   => DIA,
      DIB   => DIB,
      DOA   => DOA,
      DOB   => DOB
    );
  
end syn;
