----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:38:03 01/18/2017 
-- Design Name: 
-- Module Name:    Design_Lab_1 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Design_Lab_1 is
port(
	clk: in std_logic
);

end Design_Lab_1;

architecture Behavioral of Design_Lab_1 is


signal x: std_logic_vector(3 downto 0):="1100";
signal y: std_logic_vector(3 downto 0):="1010";
signal t: std_logic_vector(3 downto 0):="0000";


begin
		
process(y,x,t,clk)
begin
		if(rising_edge(clk)) then
			y <= std_logic_vector(unsigned(x) + 2);
			
			t <= y;
			
			x <= t;
		end if;
end process;

end Behavioral;

