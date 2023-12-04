#include "App.h"
#include <sstream>
#include <iomanip>
#include "WindowsThrowMacros.h"

App::App()
	:
	wnd(800, 600, "The Donkey Fart Box")
{}

int App::Go()
{
	while (true) {
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
	//MSG msg;
	//BOOL gResult;
	//while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	//{
	//	// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
	//	TranslateMessage(&msg);
	//	DispatchMessage(&msg);

	//	DoFrame();
	//}

	//// check if GetMessage call itself borked
	//if (gResult == -1)
	//{
	//	throw CHWND_LAST_EXCEPT();
	//}

	//// wParam here is the value passed to PostQuitMessage
	//return msg.wParam;
}

void App::DoFrame()
{
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());

}



