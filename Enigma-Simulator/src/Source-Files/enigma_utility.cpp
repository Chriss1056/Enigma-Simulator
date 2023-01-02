#include "enigma_utility.hpp"

void enigma_utility::getKey(int& returnValue, int& keyCode)
{
	returnValue = 0;
}

void enigma_utility::changeBackgroundColor(int& returnValue, backgroundColors color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!handle)
	{
		returnValue = 1;
		return;
	}
	if (!SetConsoleTextAttribute(handle, (WORD)color))
	{
		returnValue = 1;
		return;
	}
	returnValue = 0;
}

void enigma_utility::changeTextColor(int& returnValue, foregroundColors color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!handle)
	{
		returnValue = 1;
		return;
	}
	if (!SetConsoleTextAttribute(handle, (WORD)color))
	{
		returnValue = 1;
		return;
	}
	returnValue = 0;
}

void enigma_utility::cursorFillLevel(int& returnValue, int fillLevel)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO* cursorInfo = new CONSOLE_CURSOR_INFO{};
	if (!handle)
	{
		returnValue = 1;
		return;
	}
	if (!GetConsoleCursorInfo(handle, cursorInfo))
	{
		returnValue = 1;
		return;
	}
	if (!((fillLevel >= 0) && (fillLevel <= 100)))
	{
		returnValue = 1;
		return;
	}
	if (fillLevel == 0)
	{
		cursorInfo->bVisible = (BOOL)0;
	}
	else
	{
		cursorInfo->bVisible = (BOOL)1;
		cursorInfo->dwSize = (DWORD)fillLevel;
	}
	if (!SetConsoleCursorInfo(handle, cursorInfo))
	{
		returnValue = 1;
		return;
	}
	delete(cursorInfo);
	returnValue = 0;
}