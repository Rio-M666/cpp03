#include "ScavTrap.hpp"

static void	printTitle(const std::string &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
	printTitle("ClapTrap basic behavior");
	ClapTrap clap("CL4P-TP");

	clap.attack("target dummy");
	clap.takeDamage(3);
	clap.beRepaired(2);

	printTitle("ScavTrap basic behavior");
	ScavTrap scav("SC4V-TP");

	scav.attack("bandit");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	printTitle("ScavTrap copy constructor preserves independent state");
	ScavTrap original("Original");

	original.takeDamage(99);
	ScavTrap copy(original);
	copy.takeDamage(1);
	copy.attack("copy target");
	original.attack("original target");

	printTitle("ScavTrap assignment preserves independent state");
	ScavTrap assigned("temporary");

	assigned = original;
	assigned.takeDamage(1);
	assigned.attack("assigned target");
	original.attack("original target");

	printTitle("ScavTrap behavior with zero hit points");
	ScavTrap defeated("Defeated");

	defeated.takeDamage(100);
	defeated.attack("ghost");
	defeated.beRepaired(10);
	defeated.guardGate();

	printTitle("ScavTrap behavior without energy");
	ScavTrap tired("Tired");

	for (int i = 0; i < 50; i++)
		tired.attack("training dummy");
	tired.attack("training dummy");
	tired.beRepaired(1);
	tired.guardGate();
	return (0);
}
