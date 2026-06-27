#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("CL4P-TP");
	ScavTrap scav("SC4V-TP");
	ScavTrap copy(scav);

	clap.attack("target dummy");
	clap.takeDamage(3);
	clap.beRepaired(2);

	scav.attack("bandit");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	copy.attack("copy target");
	return (0);
}
