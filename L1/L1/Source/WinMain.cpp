#include <windows.h>

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

WCHAR			WindowClass[MAX_NAME_STRING];
WCHAR			WindowTitle[MAX_NAME_STRING];

INT				WindowWidth;
INT				WindowHeight;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{




	/* - Initialize Global Variables - */

	wcscpy_s(WindowClass, TEXT("TutorialOneClass"));
	wcscpy_s(WindowTitle, TEXT("Our First Window"));
	WindowWidth = 1366;
	WindowHeight = 768;





	/* - Create Window Class - */

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;//horizontal or vertical draw
	wcex.cbClsExtra = 0; //add extra memory at runtime
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);//Cursor 
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);//Background Color, Null_brush--white

	//need two icons, one for windows itself on top left corner; one for task bar
	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);//IDI_APPLICATION : basic default icon for all applications
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION);

	wcex.lpszClassName = WindowClass;

	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = DefWindowProc;//how our window perform(change size, close when finish runing in episode 2)

	RegisterClassEx(&wcex);





	/* - Create and Display our Window  - */

	 //return window handle
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,//window style
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
	    //location                                  //parent //menu               //give specific instructions during runtime
	if (!hWnd) {
		MessageBox(0, L"Failed to Create Window!.", 0, 0);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);//SW_SHOW means please show the window






	/* - Listen for Message events - */

	MSG msg = { 0 };//create a message, give command to system
	while (msg.message != WM_QUIT) 
	{
		// If there are Window messages then process them.
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);//translate and send msg to window
			DispatchMessage(&msg);
		}
	}


	return 0;

}