----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:00:27 01/18/2017 
-- Design Name: 
-- Module Name:    Q3 - Behavioral 
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

entity Q3 is
	 Generic (Speed : STD_LOGIC_VECTOR(27 downto 0) := x"1E84800"); -- 32MHz
    Port ( Switch : in  STD_LOGIC_VECTOR (3 downto 0);
           LED : out  STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
			  CLK : in STD_LOGIC
			  );
end Q3;

architecture Behavioral of Q3 is
	signal ticCounter : STD_LOGIC_VECTOR (27 downto 0) := (others => '0');
	signal counter : STD_LOGIC_VECTOR (3 downto 0):= x"0";
begin

	
	-- counter process;
	process(clk)
	begin
		if (rising_edge(clk)) then
			if (ticCounter = x"1E847FF") then
				counter <= std_logic_vector(unsigned(counter)+1);
				ticCounter <= (others => '0');
			else
				ticCounter <= std_logic_vector(unsigned(ticCounter)+1);
			end if;
		end if;
	end process;	
	

	
	-- Update LEDS
	process(clk)
	begin
		if (rising_edge(clk)) then
			LED(7) <= counter(0);
			LED(6) <= counter(1);
			LED(5) <= counter(2);
			LED(4) <= counter(3);
			LED(3 downto 0) <= Switch(3 downto 0);
		end if;
	end process;
	
end Behavioral;

