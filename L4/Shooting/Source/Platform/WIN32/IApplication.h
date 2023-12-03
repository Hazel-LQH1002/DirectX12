#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() {return new x; }
//#include "Platform/WIN32/IApplication.h"
//: public IApplication

class SHOOT_API IApplication {

	// Application

public:
	/* Application Constuctor */
	IApplication();

	/* Application Deconstructor */
	virtual ~IApplication() {};


public:
	/* Called to Initialize the Application  */
	virtual VOID Initialize() = 0;

	/* Game Loop - Called on a loop while the Application is running */
	virtual VOID Update() = 0;
};

