#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copyFrag) : ClapTrap(copyFrag)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap Constructor for the name " << this->_name << " called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Deconstructor for " << this->_name << " called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    std::cout << "FragTrap Assignation operator called" << std::endl;
    this->_name = fragTrap._name;
    this->_hit_points = fragTrap._hit_points;
    this->_energy_points = fragTrap._energy_points;
    this->_attack_damage = fragTrap._attack_damage;
    return *this;
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " << this->_name << ": You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}