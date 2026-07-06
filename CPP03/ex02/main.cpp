#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "--- ClapTrap ---" << std::endl;
    ClapTrap c("R2D2");
    c.attack("alvo");
    c.takeDamage(5);
    c.beRepaired(3);

    std::cout << "\n--- ScavTrap ---" << std::endl;
    ScavTrap s("Serena");
    s.attack("R2D2");
    s.guardGate();

    std::cout << "\n--- FragTrap ---" << std::endl;
    FragTrap f("Frag");
    f.attack("Serena");
    f.takeDamage(10);
    f.beRepaired(5);
    f.highFivesGuys();

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}