#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{
}

Application::~Application()
{
}

VOID Application::Initialize()
{
	MessageBox(0, L"I have loaded up", 0, 0);
	OutputDebugString(L"I have loaded up");
}

VOID Application::Update()
{
	//MessageBox(0, L"Loop", 0, 0);
}
