#include "Shoot.h"

#include "IApplication.h"

extern IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryApp = EntryApplication();

	EntryApp->Initialize();

	MSG msg = { 0 };//create a message, give command to system
	while (msg.message != WM_QUIT)
	{
		// If there are Window messages then process them.
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);//translate and send msg to window
			DispatchMessage(&msg);
		}
		else {
			EntryApp->Update();
		}
	}

	return 0;

}