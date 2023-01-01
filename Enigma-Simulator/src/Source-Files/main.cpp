#include <iostream>
#include "enigma_main.hpp"

int main()
{
	int returnValue = 0;
	enigma enigma;
	enigma_main::init(returnValue, enigma);
	std::cout << "Hello World." << std::endl;
	std::cin.get();
	return 0;
}