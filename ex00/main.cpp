#include "ClapTrap.hpp"

static void	printSection(const std::string &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int	main(void)
{
	printSection("Basic actions");
	ClapTrap	bob("Bob");

	bob.attack("training target");
	bob.takeDamage(3);
	bob.beRepaired(2);

	printSection("Hit point exhaustion");
	ClapTrap	fragile("Fragile");

	fragile.takeDamage(10);
	fragile.attack("anything");
	fragile.beRepaired(5);
	fragile.takeDamage(1);

	printSection("Energy exhaustion");
	ClapTrap	tired("Tired");

	for (int i = 0; i < 10; i++)
		tired.attack("practice dummy");
	tired.attack("practice dummy");
	tired.beRepaired(1);

	printSection("Copy constructor preserves independent state");
	ClapTrap	original("Original");

	original.takeDamage(9);
	ClapTrap	copy(original);
	copy.takeDamage(1);
	copy.attack("copy target");
	original.attack("original target");

	printSection("Assignment preserves independent state");
	ClapTrap	assigned;

	assigned = original;
	assigned.takeDamage(1);
	assigned.attack("assigned target");
	original.attack("original target");
	return (0);
}
