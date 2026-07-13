#include"FragTrap.hpp"

FragTrap::FragTrap() 
{
    std::cout<<"FragTrap default constructor called\n"<<std::endl;
    this->_hitPoints=100;
    this->_energyPoints=100;
    this->_attackDamage=30;


}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout<<"FragTrap Name constructor called"<<std::endl;
    this->_hitPoints=100;
    this->_energyPoints=100;
    this->_attackDamage=30;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout<<"FragTrap Copy constructor called"<<std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}
FragTrap::~FragTrap()
{
    std::cout<<"FragTrap Destructor called"<<std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name<< " has no hit points left" << std::endl;
	}
	else if (this->_energyPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "FragTrap " << this->_name<< " has no energy points left" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (_hitPoints == 0)
	{
    	std::cout << "FragTrap cannot request a high five because it has no hit points."
              << std::endl;
    	return;
	}
	std::cout << "FragTrap requests a high five!" << std::endl;
}
