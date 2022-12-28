#include "enigma_main.hpp"

void enigma_main::init(int& returnValue, struct enigma& enigma)
{
}

void enigma_main::saveMessageToFile(int& returnValue, struct enigma& enigma)
{
	std::fstream file;
	file.open(enigma.fileName, std::ios::_Nocreate | std::ios::binary | std::ios::trunc | std::ios::out);
	if (!file)
	{
		returnValue = 1;
		return;
	}
	for (int i = 0; i < enigma.msg.size(); i++)
	{
		file << enigma.msg[i];
	}
	file.close();
}

void enigma_main::loadMessageFromFile(int& returnValue, struct enigma& enigma)
{
	std::fstream file;
	file.open(enigma.fileName, std::ios::_Nocreate | std::ios::binary | std::ios::in);
	if (!file)
	{
		returnValue = 1;
		return;
	}
	file.seekg(0, std::ios::end);
	int fileSize = file.tellg();
	file.seekg(0, std::ios::beg);
	enigma.msg.resize(fileSize);
	char tmp[sizeof(fileSize)];
	file.read(tmp, enigma.msg.size());
	for (int i = 0; i < enigma.msg.size(); i++)
	{
		enigma.msg[i] = tmp[i];
	}
	free(tmp);
	file.close();
}


void enigma_main::generateKey(int& returnValue)
{
}

void enigma_main::encryptMessageWithKey(int& returnValue)
{
}

void enigma_main::decryptMessageWithKey(int& returnValue)
{
}


void enigma_main::saveKeyToFile(int& returnValue)
{
}

void enigma_main::loadKeyFromFile(int& returnValue)
{
}