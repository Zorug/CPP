#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot1("R2D2");
    ClapTrap robot2("C3PO");

    robot1.attack("C3PO");
    robot2.takeDamage(0);
    robot2.beRepaired(5);
    robot1.attack("C3PO");
    robot2.takeDamage(0);
    robot2.beRepaired(3);
    
    return 0;
}
