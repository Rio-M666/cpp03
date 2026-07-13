#include "FragTrap.hpp"
#include "ScavTrap.hpp"

static void	printTitle(const std::string &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
	printTitle("ScavTrap still works in ex02");
	ScavTrap scav("SC4V-TP");

	scav.attack("bandit");
	scav.guardGate();
	scav.takeDamage(100);
	scav.attack("ghost");
	scav.beRepaired(10);
	scav.guardGate();

	printTitle("FragTrap basic behavior");
	FragTrap alpha("Alpha");

	alpha.attack("training dummy");
	alpha.takeDamage(40);
	alpha.beRepaired(15);
	alpha.highFivesGuys();

	printTitle("FragTrap copy constructor preserves independent state");
	FragTrap original("Original");

	original.takeDamage(99);
	FragTrap copy(original);
	copy.takeDamage(1);
	copy.attack("copy target");
	copy.highFivesGuys();
	original.highFivesGuys();

	printTitle("FragTrap assignment preserves independent state");
	FragTrap assigned("Temporary");

	assigned = original;
	assigned.takeDamage(1);
	assigned.attack("assigned target");
	assigned.highFivesGuys();
	original.highFivesGuys();

	printTitle("FragTrap behavior with zero hit points");
	FragTrap defeated("Defeated");

	defeated.takeDamage(100);
	defeated.attack("ghost");
	defeated.beRepaired(10);
	defeated.highFivesGuys();

	printTitle("FragTrap behavior without energy");
	FragTrap tired("Tired");

	for (int i = 0; i < 100; i++)
		tired.attack("training dummy");
	tired.attack("training dummy");
	tired.beRepaired(1);
	tired.highFivesGuys();
	return (0);
}
