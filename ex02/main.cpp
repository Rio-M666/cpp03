#include "FragTrap.hpp"

int main(void)
{
	FragTrap alpha("Alpha");
	FragTrap beta(alpha);

	alpha.attack("training dummy");
	alpha.highFivesGuys();
	beta.highFivesGuys();
	return (0);
}
