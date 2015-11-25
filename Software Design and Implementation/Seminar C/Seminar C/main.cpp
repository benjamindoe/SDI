
#include <iostream>
#include "SDI.cpp"

using namespace std;

int main(int argc, char * argv[])
{
	parseArgs(argc, argv);
	parseArgsFlags(argc, argv);
	parseArgsValues(argc, argv);
	return 0;
}

