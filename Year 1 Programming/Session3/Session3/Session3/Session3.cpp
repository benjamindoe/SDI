// Session3.cpp : Defines the entry point for the console application.
//
// Framework for experimentation with loops and arrays
// This example contains 3 errors and is also not ideal in some other ways
// Find the errors first
// Then check that it gives correct results for a range of values
// Then add code to keep asking the user for input if they enter stupid numbers
// Then modify it so that it averages over 10 days instead


#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	/*int pollution_level[6];
	int average = 0;
	int counter =0;
	const int maxCounter = 9;
	while (counter <= maxCounter){
		cout<<"Enter pollution level for day "<<counter<<" range (1-100): ";
		cin>>pollution_level[counter];
		if (average <= 100 && average >= 1){
			average = average + pollution_level[counter];
			counter++;
		}
		else{
			cout << "Invalid Input. Range (1-100)." << endl;
		}
	}
	cout<<endl;
	cout<< "The average pollution level over those 6 days was :"<<average/6<<endl;*/
	float myArray[10] = { 6.7, 5.1, 9.6, 4.6, 10.3, 10.2, 4.6, 6.9, 7.9, 2.1 };
	const int arrayLength = 9;
	int hArrayIndex = -1;
	int lArrayIndex = -1;
	float highest = -1;
	float lowest = -1;
	for (int i = 0; i <= 9; i++){
		if (highest < myArray[i] || highest < 0){
			highest = myArray[i];
			hArrayIndex = i;
		}
		else if (lowest < 0 || lowest > myArray[i]){
			lowest = myArray[i];
				lArrayIndex = i;
		}
	}
	cout << "Highest value: " << highest << " at index: " << hArrayIndex << endl;
	cout << "Lowest value: " << lowest << " at index: " << lArrayIndex << endl;
	return 0;
}
// After you've done the previous parts, comment out the code between the first { and the return 0;, then do the following
//Part c – Simple averages
//1.Declare an array to hold 10 floating point values, and initialise them to something non-zero.
//2.Write a loop (a while or a for) to go through each of the elements in the array and add its value to a running total. 
//3.After the loop, display the average of these values. Check your answer.
//Part d – Finding the highest/lowest
//1.Initialise an array of floats as above. Set up an integer variable to record an index into the array (initialise it to -1 to indicate it is invalid), and a float variable to hold the highest value of that element in the array.
//2.Use a loop to go through (iterate) the array, and record the index of the element with the highest value in the array, by comparing the value of each element in turn against the currently stored highest value. 
//3.If an element has a higher value, record its index in the integer variable, and replace the value stored as the highest with the new winner.
//4.After the loop display the index of the winning value and the highest value
//5.Modify the program so that it displays both the highest and lowest values


