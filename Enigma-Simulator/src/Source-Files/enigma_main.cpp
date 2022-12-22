#include "enigma_main.hpp"

void enigma_main::init()
{
}

void enigma_main::saveMessageToFile(int& returnValue, const char*& fileName, std::vector<char>& msg)
{
	std::fstream file;
	file.open(fileName, std::ios::_Nocreate | std::ios::binary | std::ios::trunc | std::ios::out);
	if (!file)
	{
		returnValue = 1;
		return;
	}
	for (int i = 0; i < msg.size(); i++)
	{
		file << msg[i];
	}
	file.close();
}

void enigma_main::loadMessageFromFile(int& returnValue, const char*& fileName, std::vector<char>& msg)
{
	std::fstream file;
	file.open(fileName, std::ios::_Nocreate | std::ios::binary | std::ios::in);
	if (!file)
	{
		returnValue = 1;
		return;
	}
	file.seekg(0, std::ios::end);
	int fileSize = file.tellg();
	file.seekg(0, std::ios::beg);
	msg.resize(fileSize);
	char tmp[sizeof(fileSize)];
	file.read(tmp, msg.size());
	for (int i = 0; i < msg.size(); i++)
	{
		msg[i] = tmp[i];
	}
	free(tmp);
	file.close();
}


void enigma_main::generateKeypair(int& returnValue)
{
}

void enigma_main::encryptMessageWithKey(int& returnValue)
{
}

void enigma_main::decryptMessageWithKey(int& returnValue)
{
}


void enigma_main::savePublicKeyToFile(int& returnValue)
{
}

void enigma_main::loadPublicKeyFromFile(int& returnValue)
{
}


void enigma_main::savePrivateKeyToFile(int& returnValue)
{
}

void enigma_main::loadPrivateKeyFromFile(int& returnValue)
{
}
