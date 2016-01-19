#include <iostream>
#include "calculator.h"

using namespace std;
int main(int argc, char * argv[])
{
	Calculator calc;
	cout << calc.add(32, 45) << endl;
	cout << calc.subtract(32, 45) << endl;
	cout << calc.divide(32, 45) << endl;
	cout << calc.multiply(32, 45) << endl;
}