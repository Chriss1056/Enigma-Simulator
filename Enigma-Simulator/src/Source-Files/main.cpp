#include <iostream>
#include "enigma_main.hpp"

int main()
{
	int returnValue = 0;
	enigma_main::generateKey(returnValue);
	std::cout << "Hello World." << std::endl;
	std::cin.get();
	return 0;
}