#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->_gate_protector = false;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copyScav) : ClapTrap(copyScav)
{
    this->_gate_protector = copyScav._gate_protector;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->_gate_protector = false;
    std::cout << "ScavTrap Constructor for the name " << this->_name << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstructor for " << this->_name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    this->_name = scavTrap._name;
    this->_hit_points = scavTrap._hit_points;
    this->_energy_points = scavTrap._energy_points;
    this->_attack_damage = scavTrap._attack_damage;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hit_points <= 0)
        std::cout << "\033[31mClapTrap " << this->_alias << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
    else if (this->_energy_points == 0)
        std::cout << "\033[31mClapTrap " << this->_alias << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_alias << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
}

void ScavTrap::guardGate(void)
{
    if (this->_gate_protector == false)
    {
        this->_gate_protector = true;
        std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
    }
    else
        std::cout << "\033[33mScavTrap " << this->_name << " is already guarding the gate.\033[0m" << std::endl;
}