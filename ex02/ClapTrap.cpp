#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copyClap)
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = copyClap;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap Constructor for the name " << this->_name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Deconstructor for " << this->_name << " called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    this->_name = clapTrap._name;
    this->_hit_points = clapTrap._hit_points;
    this->_energy_points = clapTrap._energy_points;
    this->_attack_damage = clapTrap._attack_damage;
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_hit_points <= 0)
        std::cout << "\033[31mClapTrap " << this->_alias << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
    else if (this->_energy_points == 0)
        std::cout << "\033[31mClapTrap " << this->_alias << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_alias << " attacks " << target << ", causing " << this->_power << " points of damage!" << std::endl;
        this->_energy_points--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points <= 0)
    {
        std::cout << "\033[33mClapTrap " << this->_alias << " is already dead, stop beating it.\033[0m" << std::endl;
        return;
    }
    if (this->_hit_points <= amount)
        this->_hit_points = 0;
    else
        this->_hit_points -= amount;
    std::cout << "ClapTrap " << this->_alias << " was attacked and lost " << amount << " hit points, he now has " << this->_hit_points << " hit points." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_points <= 0)
        std::cout << "\033[31mClapTrap " << this->_alias << " is not able to repair itself, because he doesn't have enough hit points.\033[0m" << std::endl;
    else if (this->_energy_points == 0)
        std::cout << "\033[31mClapTrap " << this->_alias << " is not able to repair itself, because he doesn't have enough energy points.\033[0m" << std::endl;
    else if (this->_hit_points + amount > 10)
        std::cout << "\033[33mClapTrap " << this->_alias << " can't be repaired to have more than 10 hit points.\033[0m" << std::endl;
    else
    {
        this->_hit_points += amount;
        std::cout << "ClapTrap " << this->_alias << " repaired itself and gained " << amount << " of hit points, he now has " << this->_hit_points << "hit points." << std::endl;
        this->_energy_points--;
    }
}

std::string	ClapTrap::getName() const{
	return (_name);
}

int	ClapTrap::getHitPoints() const{
	return (_hit_points);
}

int	ClapTrap::getEnergyPoints() const{
	return (_energy_points);
}

int	ClapTrap::getAttackDamage() const{
	return (_attack_damage);
}