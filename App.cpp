#include "App.h"
#include <sstream>
#include <iomanip>
#include <math.h>


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
	const float r = sin(timer.Peek()) / 2.0f + 0.5f;
	const float g = sin(timer.Peek() + 3.14f/2) / 2.0f + 0.5f;
	const float b = sin(timer.Peek() + 3.14f) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(r, g, b);
	wnd.Gfx().DrawTestCube(timer.Peek(),
							   wnd.mouse.GetPosX() / 400.0f -1.0f, 
							   wnd.mouse.GetPosY() / 300.0f -1.0f );
	wnd.Gfx().EndFrame();
}