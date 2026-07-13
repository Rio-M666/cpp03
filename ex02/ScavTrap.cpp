#include"ScavTrap.hpp"

ScavTrap::ScavTrap() 
{
    std::cout<<"ScavTrap default constructor called\n"<<std::endl;
    this->_hitPoints=100;
    this->_energyPoints=50;
    this->_attackDamage=20;
    this->_is_guardGate=false;

}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout<<"ScavTrap Name constructor called"<<std::endl;
    this->_hitPoints=100;
    this->_energyPoints=50;
    this->_attackDamage=20;
    this->_is_guardGate=false;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other),
	_is_guardGate(other._is_guardGate)
{
    std::cout<<"ScavTrap Copy constructor called"<<std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
    this->_is_guardGate=other._is_guardGate;
	return (*this);
}
ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap Destructor called"<<std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name<< " has no hit points left" << std::endl;
	}
	else if (this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << this->_name<< " has no energy points left" << std::endl;
}

void ScavTrap::guardGate()
{
	this->_is_guardGate = true;
	std::cout << "ScavTrap " << this->_name
			  << " is now in Gate keeper mode" << std::endl;
}

