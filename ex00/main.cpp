#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("Bob");

	bob.attack("training target");
	bob.takeDamage(3);
	bob.beRepaired(2);
	return (0);
}
