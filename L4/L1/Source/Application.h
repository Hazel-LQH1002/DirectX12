#pragma once


#include "Platform/WIN32/IApplication.h"

//#include "Platform/WIN32/IApplication.h"
//: public IApplication

class Application:public IApplication {

	// Application

public:
	/* Application Constuctor */
	Application();

	/* Application Deconstructor */
	~Application();


public:
	/* Called to Initialize the Application  */
	VOID Initialize();

	/* Game Loop - Called on a loop while the Application is running */
	VOID Update();
};