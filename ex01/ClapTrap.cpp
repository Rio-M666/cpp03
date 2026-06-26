
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
	_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " has no hit points left" << std::endl;
	}
	else if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamage
				  << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << this->_name
				  << " has no energy points left" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "You are already dead" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount
				  << " points of damage" << std::endl;
		if (amount > this->_hitPoints)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "You are already dead" << std::endl;
	}
	else if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repaired " << amount
				  << " hit points" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << this->_name
				  << " has no energy points left" << std::endl;
}
