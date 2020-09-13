#include "Window.h"
#include "utils.h"
#include "sstream"

int CALLBACK WinMain(
	HINSTANCE hInctance,
	HINSTANCE hPrevInstance,
	LPSTR IpCmdLine,
	int nCndShow)
{
	try
	{
		Window wnd(640, 640, L"You yo yo");
		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			// app logic test
			while (! wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				if (e.GetType() == Mouse::Event::Type::Move)
				{
					std::wostringstream woss;
					woss << "Mouse Position (" << e.GetPosX() << ","
						 << e.GetPosY() << ")";
					wnd.SetTitle(woss.str());
				}
				if (e.GetType() == Mouse::Event::Type::LPress)
				{
					std::wostringstream woss;
					woss << "LEFT";
					wnd.SetTitle(woss.str());
				}
				if (e.GetType() == Mouse::Event::Type::MPress)
				{
					std::wostringstream woss;
					woss << "MID";
					wnd.SetTitle(woss.str());
				}
			}
		}

		if (gResult == -1)
		{
			return -1;
		}
		return msg.wParam;
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