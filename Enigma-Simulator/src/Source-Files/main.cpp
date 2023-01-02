#include <iostream>
#include "enigma_main.hpp"

int main()
{
	int returnValue = 0;
	enigma enigma;
	enigma_utility::cursorFillLevel(returnValue, 75);
	std::cout << "Hello World." << std::endl;
	std::cin.get();
	return 0;
}