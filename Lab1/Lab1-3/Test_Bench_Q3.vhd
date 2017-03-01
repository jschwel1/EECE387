--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:26:56 01/18/2017
-- Design Name:   
-- Module Name:   C:/Users/Jacob/Desktop/VHDL/EECE387/Lab1-3/Test_Bench_Q3.vhd
-- Project Name:  Lab1-3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Q3
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
 
ENTITY Test_Bench_Q3 IS
END Test_Bench_Q3;
 
ARCHITECTURE behavior OF Test_Bench_Q3 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Q3
    PORT(
         Switch : IN  std_logic_vector(3 downto 0);
         LED : OUT  std_logic_vector(7 downto 0);
         CLK : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal Switch : std_logic_vector(3 downto 0) := x"3";
   signal CLK : std_logic := '0';

 	--Outputs
   signal LED : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 1 ms;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Q3 PORT MAP (
          Switch => Switch,
          LED => LED,
          CLK => CLK
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
   --   wait for 100 ns;	
		  wait for 30 ms;
			Switch <= x"7";

      -- insert stimulus here 

      wait;
   end process;

END;
