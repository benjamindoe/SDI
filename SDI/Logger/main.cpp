#include "logger.h"

int main(int argc, char * argv[])
{
	SDI::Logger myLog(argc, argv);
	myLog.log("ERR", "This is a test error");
	myLog.setLevel("NONE");
	return 0;
}