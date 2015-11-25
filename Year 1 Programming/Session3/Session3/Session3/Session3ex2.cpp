// Description:
// Use of function to imrpve program structure

#include "stdafx.h"
#include <iostream>
using namespace std;


const int MAXDAYS=6;

// function declaration
int GetValidPollution(int Day);

int main()
{
	int pollution_level[MAXDAYS];
	double average=0.0;
	int counter =0;
	while (counter<MAXDAYS)
	{
		pollution_level[counter] = GetValidPollution(counter);
		average = average + pollution_level[counter];
		counter++;
	}

	cout<<endl;
	cout<< "The average pollution level over those "<<MAXDAYS<<" days was : "<<average/MAXDAYS<<endl;

	return 0;
}

//function definition
int GetValidPollution(int Day)
{
	int temp;
	cout<<"Enter pollution level for day "<<Day<<" range (1-100): ";
	cin>>temp;
	if (temp > 100 || temp < 1 || !cin){
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid Input. Please input a value between 1 and 100." << endl;
		temp = GetValidPollution(Day);
	}
	return temp;
}