#pragma once

#include <vector>
#include <fstream>
#include <ctime>

#include "enigma_utility.hpp"

class enigma
{
public:
	std::vector<std::vector<int>> rotors;
	std::vector<int> positions;
	const char* fileName;
	std::vector<char> msg;
	std::tm* time;
};

namespace enigma_main
{
	void init(int& returnValue, class enigma& enigma);

	void saveMessageToFile(int& returnValue, class enigma& enigma);
	void loadMessageFromFile(int& returnValue, class enigma& enigma);

	void generateKey(int& returnValue, class enigma& enigma);
	void encryptMessageWithKey(int& returnValue, class enigma& enigma);
	void decryptMessageWithKey(int& returnValue, class enigma& enigma);

	void saveKeyToFile(int& returnValue, class enigma& enigma);
	void loadKeyFromFile(int& returnValue, class enigma& enigma);
}