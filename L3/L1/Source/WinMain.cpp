#include "pch.h"


/* ------------------------------------------------------ */
/*  Global Variables                                      */
/* ------------------------------------------------------ */
#pragma region GlobalVariables

WCHAR			WindowClass[MAX_NAME_STRING];
WCHAR			WindowTitle[MAX_NAME_STRING];
INT				WindowWidth;
INT				WindowHeight;
HICON			hIcon;
#pragma endregion
/* ------------------------------------------------------ */



/* ------------------------------------------------------ */
/*  Pre-Declarations                                      */
/* ------------------------------------------------------ */
#pragma region Pre-Declarations

VOID InitializeVariables();
VOID CreateWindowClass();
VOID InitializeWindow();
VOID MessageLoop();
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);
#pragma endregion
/* ------------------------------------------------------ */


#pragma region Operations

//int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
//{
//	/* - Initialize Global Variables - */
//	
//	InitializeVariables();
//
//	/* - Create Window Class - */
//
//	CreateWindowClass();
//
//	/* - Create and Display our Window  - */
//
//	InitializeWindow();
//
//	/* - Listen for Message events - */
//	MessageLoop();
//
//	return 0;
//
//}

//hWnd: window handle //message: message type //waparam,lparam:arguement of the msg 
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wparam, lparam);
}
#pragma endregion



/* ------------------------------------------------------ */
/*  Functions                                             */
/* ------------------------------------------------------ */

VOID InitializeVariables() {
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);
	WindowWidth = 1366;
	WindowHeight = 768;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

VOID CreateWindowClass()
{

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;//horizontal or vertical draw
	wcex.cbClsExtra = 0; //add extra memory at runtime
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);//Cursor 
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);//Background Color, Null_brush--white

	//need two icons, one for windows itself on top left corner; one for task bar
	wcex.hIcon = hIcon;//IDI_APPLICATION : basic default icon for all applications
	wcex.hIconSm = hIcon;

	wcex.lpszClassName = WindowClass;

	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = WindowProcess;//how our window perform(change size, close when finish runing in episode 2)

	RegisterClassEx(&wcex);
}

VOID InitializeWindow() {
	//return window handle
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,//window style
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
	//location                                  //parent //menu               //give specific instructions during runtime
	if (!hWnd) {
		MessageBox(0, L"Failed to Create Window!.", 0, 0);
		PostQuitMessage(0);
	}

	ShowWindow(hWnd, SW_SHOW);//SW_SHOW means please show the window
}

VOID MessageLoop() {
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
}

/* ------------------------------------------------------ */