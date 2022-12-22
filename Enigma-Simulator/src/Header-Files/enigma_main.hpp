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
	void saveMessageToFile(int& returnValue, struct enigma& enigma);
	void loadMessageFromFile(int& returnValue, struct enigma& enigma);

	void generateKeypair(int& returnValue);
	void encryptMessageWithKey(int& returnValue);
	void decryptMessageWithKey(int& returnValue);

	void savePublicKeyToFile(int& returnValue);
	void loadPublicKeyFromFile(int& returnValue);

	void savePrivateKeyToFile(int& returnValue);
	void loadPrivateKeyFromFile(int& returnValue);
}