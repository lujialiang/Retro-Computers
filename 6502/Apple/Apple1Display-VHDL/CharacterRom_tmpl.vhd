-- VHDL module instantiation generated by SCUBA Diamond (64-bit) 3.10.2.115
-- Module  Version: 5.4
-- Mon Aug 05 13:43:51 2019

-- parameterized module component declaration
component CharacterRom
    port (Address: in  std_logic_vector(8 downto 0); 
        OutClock: in  std_logic; OutClockEn: in  std_logic; 
        Reset: in  std_logic; Q: out  std_logic_vector(4 downto 0));
end component;

-- parameterized module component instance
__ : CharacterRom
    port map (Address(8 downto 0)=>__, OutClock=>__, OutClockEn=>__, 
        Reset=>__, Q(4 downto 0)=>__);
