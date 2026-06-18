#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
// When attributes are private, only the class itself 
// can access them — not even child classes. 
/*private:
	std::string _name; // parameter to the constructor
	unsigned int _hitPoints; // (10) - health of the ClapTrap
	unsigned int _energyPoints; // (10)
	unsigned int _attackDamage; // (0)*/

// Outside code (like main) cannot access it directly
// 		→ same as private
// Child classes can access it directly
// 		→ unlike private
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