#include <string>
#include <sstream>
#include "Window.h"


////LRESULT: 32bit int                //msg ID
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
//	switch (msg) {
//	case WM_CLOSE:
//		PostQuitMessage(69);
//		break;
//	case WM_KEYDOWN:
//		if (wParam == 'F') {
//			SetWindowText(hWnd, "Change Title");
//		}
//		break;
//	//case WM_CHAR:
//	//{
//	//	static std::string title;
//	//	title.push_back((char)wParam);
//	//	SetWindowText(hWnd, title.c_str());
//	//}
//
//
//	case WM_LBUTTONDOWN:
//	{
//		POINTS pt = MAKEPOINTS(lParam);
//		std::ostringstream oss;
//		oss << "(" << pt.x << "," << pt.y << ")";
//
// 	}
//	}
//	
//
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{

	///* Display Window */
	Window wnd(800,300, "My Window");

	/* Get Message */
	MSG msg;                //nullptr, means get message from all windows  //0,0 means accept all msg
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0) > 0)) { //if = 0, retrieves WM_QUIT; < 0 then error 
		TranslateMessage(&msg); //will not modify msg, translate virtual key msg to character msg
		DispatchMessage(&msg);//pass the msg to win32 procedure
		////VK_MENU is ALT key
		if (wnd.kbd.KeyIsPressed(VK_MENU)) {
			MessageBox(nullptr, "Something Happen!", "Space Key Was Pressed", MB_OK | MB_ICONEXCLAMATION);
		}
		static int i = 0;
		while (!wnd.mouse.IsEmpty()) {
			const auto e = wnd.mouse.Read();
			switch (e.GetType())
			{
			case Mouse::Event::Type::Leave:

				wnd.SetTitle("Mouse Gone");
				break;

			//case Mouse::Event::Type::Move:
			//{
			//	std::ostringstream oss;
			//	oss << "Mouse Position: (" << e.GetPosX() << "," << e.GetPosY() << ")";
			//	wnd.SetTitle(oss.str());

			//}
			//break;
			case Mouse::Event::Type::WheelUp:
				i++;
				{
					std::ostringstream oss;
					oss << "Up: " << i;
					wnd.SetTitle(oss.str());
				}
				break;
			case Mouse::Event::Type::WheelDown:
				i--;
				{
					std::ostringstream oss;
					oss << "Down: " << i;
					wnd.SetTitle(oss.str());
				}
				break;
			}
		}
	}

	if (gResult == -1) {
		return -1;
	}
	else {
		return msg.wParam;//if WM_QUIT, it will keep the msg value in wParam
	}

	return 0;
}