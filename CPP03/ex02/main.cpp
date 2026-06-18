#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap robot1("R2D2");
    robot1.attack("C3PO");

    std::cout << "---" << std::endl;

    ScavTrap scav("Serena");
    scav.attack("R2D2");
    scav.guardGate();

    return 0;
}