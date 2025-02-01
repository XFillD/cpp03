#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    bool _gate_protector;

public:
    ScavTrap();
    ScavTrap(const ScavTrap &copyScav);
    ScavTrap(std::string name);

    virtual ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &scavTrap);

    void attack(const std::string &target);
    void guardGate(void);
};