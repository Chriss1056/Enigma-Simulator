#pragma once

#include <vector>
#include <fstream>

struct enigma
{
	std::vector<std::vector<int>> walzen;
	std::vector<int> positions;
	const char*& fileName;
	std::vector<char>& msg;
};

namespace enigma_main
{
	void init(int& returnValue, struct enigma& enigma);

	void saveMessageToFile(int& returnValue, struct enigma& enigma);
	void loadMessageFromFile(int& returnValue, struct enigma& enigma);

	void generateKey(int& returnValue);
	void encryptMessageWithKey(int& returnValue);
	void decryptMessageWithKey(int& returnValue);

	void saveKeyToFile(int& returnValue);
	void loadKeyFromFile(int& returnValue);
}