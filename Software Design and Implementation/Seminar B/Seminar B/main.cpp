
#include <iostream>
#include "DynArray.h"

using namespace std;
int main()
{
	SDI::DynArray<int> MyDyn(2);

	for (int i = 0; i < 50; i++)
	{
		MyDyn.push_back(i + 1);
	}

	cout << MyDyn.front() << endl;
	cout << MyDyn.back() << endl;
	cout << MyDyn.get(2) << endl;
	return 0;
}