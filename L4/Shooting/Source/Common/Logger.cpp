#include "Shoot.h"



Logger* Logger::inst;


Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{
}
