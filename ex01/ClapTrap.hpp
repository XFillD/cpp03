#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;

public:
    ClapTrap();
    ClapTrap(const ClapTrap &copyClap);
    ClapTrap(std::string name);

    virtual ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &clapTrap);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
};