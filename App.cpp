#include "App.h"
#include <sstream>
#include <iomanip>


App::App()
	:
	wnd(800, 600, L"Yo yo yo")
{}

int App::Go()
{
	MSG msg;
	while ( true )
	{
		//process all messages pending, but to not block
		if (const auto ecode = Window::ProcessMessages())
		{
			//if returned optional ecode has value -> we have a message 
			return *ecode;
		}
		DoFrame();
	}

	//wParam here is the value passed to PostQuitMessage
	return msg.wParam;
}

void App::DoFrame()
{
	const float t = timer.Peek();
	std::wostringstream woss;
	woss << L"Времени прошло: " << std::setprecision(1)
		 << std::fixed << t << L" секунд";
	wnd.SetTitle(woss.str());

}