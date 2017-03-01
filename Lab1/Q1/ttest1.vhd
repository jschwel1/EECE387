--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:09:18 01/18/2017
-- Design Name:   
-- Module Name:   C:/Design_Lab_1/Lab1/ttest1.vhd
-- Project Name:  Lab1
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Design_Lab_1
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY ttest1 IS
END ttest1;
 
ARCHITECTURE behavior OF ttest1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Design_Lab_1
    --PORT(
     --   );
    END COMPONENT;
    
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
  -- constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Design_Lab_1; --PORT MAP (
       -- );

   -- Clock process definitions
  -- <clock>_process :process
  -- begin
		--<clock> <= '0';
		--wait for <clock>_period/2;
	--	<clock> <= '1';
	--	wait for <clock>_period/2;
  -- end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

    --  wait for <clock>_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
