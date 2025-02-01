#include "../include/ClapTrap.hpp"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("ClapClap");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("some other ClapClap");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other ClapClap");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("ClapClap-clone");
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}