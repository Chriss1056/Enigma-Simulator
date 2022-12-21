#pragma once

#include <vector>
#include <fstream>

struct enigma
{
	std::vector<std::vector<int>> walzen;
	std::vector<int> positions;
};

namespace enigma_main
{
	void init();

	void saveMessageToFile(int& returnValue, const char*& fileName, std::vector<char>& msg);
	void loadMessageFromFile(int& returnValue, const char*& fileName, std::vector<char>& msg);

	void generateKeypair(int& returnValue);
	void encryptMessageWithKey(int& returnValue);
	void decryptMessageWithKey(int& returnValue);

	void savePublicKeyToFile(int& returnValue);
	void loadPublicKeyFromFile(int& returnValue);

	void savePrivateKeyToFile(int& returnValue);
	void loadPrivateKeyFromFile(int& returnValue);
}