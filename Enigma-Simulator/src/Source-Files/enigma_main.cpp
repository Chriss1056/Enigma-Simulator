#include "enigma_main.hpp"

void enigma_main::init(int& returnValue, class enigma& enigma)
{
	const char* rotorstmp[] = { "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
								"AJDKSIRUXBLHWTMCQGZNPYFVOE",
								"BDFHJLCPRTXVZNYEIWGAKMUSQO",
								"ESOVPZJAYQUIRHXLNFTGKDCMWB",
								"VZBRGITYUPSDNHLXAWMJQOFECK",
								"JPGVOUMFYQBENHZRDKASXLICTW",
								"NZJHGRCXMYSWBOUFAIVLPEKQDT",
								"FKQHTLXOCBJSPDZRAMEWNIUYGV" };
	
	enigma.rotors.resize(8);
	for (int x = 0; x < enigma.rotors.size(); x++)
	{
		enigma.rotors[x].resize(26);
	}

	for (int x = 0; x < enigma.rotors.size(); x++)
	{
		for (int y = 0; y < enigma.rotors[x].size(); y++)
		{
			enigma.rotors[x][y] = rotorstmp[x][y];
		}
	}

	enigma.positions.resize(8);
	for (int i = 0; i < enigma.positions.size(); i++)
	{
		enigma.positions[i] = 0;
	}

	enigma.msg.resize(1);
	enigma.msg[0] = '\0';

	enigma.time = nullptr;

	returnValue = 0;
}

void enigma_main::saveMessageToFile(int& returnValue, class enigma& enigma)
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

void enigma_main::loadMessageFromFile(int& returnValue, class enigma& enigma)
{
	std::fstream file;
	file.open(enigma.fileName, std::ios::_Nocreate | std::ios::binary | std::ios::in);
	if (!file)
	{
		returnValue = 1;
		return;
	}
	file.seekg(0, std::ios::end);
	std::streamoff fileSize = file.tellg();
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


void enigma_main::generateKey(int& returnValue, class enigma& enigma)
{
	std::time_t tmp = std::time(0);
#pragma warning(suppress : 4996)
	enigma.time = std::gmtime(&tmp);
#pragma warning(default : 4996)
	enigma.time->tm_year = enigma.time->tm_year + 1900;
	enigma.time->tm_mon = enigma.time->tm_mon + 1;
}

void enigma_main::encryptMessageWithKey(int& returnValue, class enigma& enigma)
{
}

void enigma_main::decryptMessageWithKey(int& returnValue, class enigma& enigma)
{
}


void enigma_main::saveKeyToFile(int& returnValue, class enigma& enigma)
{
}

void enigma_main::loadKeyFromFile(int& returnValue, class enigma& enigma)
{
}