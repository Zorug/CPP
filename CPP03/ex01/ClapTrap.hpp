#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
/*private:
	std::string _name; // parameter to the constructor
	unsigned int _hitPoints; // (10) - health of the ClapTrap
	unsigned int _energyPoints; // (10)
	unsigned int _attackDamage; // (0)*/

protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	// Orthodox Canonical Form
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	// Member functions
	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );
};

# endif