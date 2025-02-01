#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
public:
    FragTrap();
    FragTrap(const FragTrap &copyFrag);
    FragTrap(std::string name);

    virtual ~FragTrap();

    FragTrap &operator=(const FragTrap &fragTrap);

    void highFiveGuys(void);
};