#include "Window.h"
#include "utils.h"
#include "sstream"
#include "App.h"

int CALLBACK WinMain(
	HINSTANCE hInctance,
	HINSTANCE hPrevInstance,
	LPSTR IpCmdLine,
	int nCndShow)
{
	try
	{
		return App().Go();
	}
	catch (const EngineException& e)
	{
		MessageBox(nullptr, e.GetWhat().c_str(), CharToLPWSTR(e.GetType()), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{

		MessageBox(nullptr, CharToLPWSTR(e.what()), L"Standart Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, L"No datails available", L"Uknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
}