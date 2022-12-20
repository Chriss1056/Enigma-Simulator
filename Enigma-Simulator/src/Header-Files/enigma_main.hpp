#pragma once

#include <vector>

struct enigma
{
	std::vector<std::vector<int>> walzen;
	std::vector<int> positions;
};

namespace enigma_main
{
	void init();

	void saveToFile();
	void loadFromFile();

	void generateKeypair();
	void encryptMessageWithKey();
	void decryptMessageWithKey();

	void savePublicKeyToFile();
	void loadPublicKeyToFile();

	void savePrivateKeyToFile();
	void loadPrivateKeyToFile();
}