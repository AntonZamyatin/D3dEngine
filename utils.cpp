#include "utils.h"

LPWSTR CharToLPWSTR(const char* text) noexcept
{
	size_t size = strlen(text) + 1;
	wchar_t* wtext = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, wtext, size, text, size - 1);

	return wtext;
}