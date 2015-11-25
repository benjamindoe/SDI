// Description: example of a struct in use

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Simple
{
	int Element1;
	double Element2;
}; // note the semicolon

double PointlessFunction(Simple ArbitraryParameter);
struct Patiant{
	double height;
	double weight;
	int age;
	bool isMale;
};
int main(){
	//Simple AVariable = {99, 2.5}; //doing some initialising
	//Simple BVariable;
	//Simple TestArray[4];
	//const int maxIndex = 3;
	//double ResultA;
	//double ResultB;
	//
	//// setting values for parts of the struct
	//BVariable.Element1 =-42;
	//BVariable.Element2 = 3.14159;
	//// passing a variable of our new type Simple to a function 
	//ResultA= PointlessFunction(AVariable);
	//ResultB= PointlessFunction(BVariable);
	//cout<<"Value of ResultA  "<<ResultA<<endl;
	//cout<<"Value of ResultB  "<<ResultB<<endl;
	//for (int i = 0; i <= maxIndex; i++){
	//	TestArray[i].Element1 = i + 2;
	//	TestArray[i].Element2 = i*1.5;
	//}
	//for (int i = 0; i <= maxIndex; i++){
	//	cout << PointlessFunction(TestArray[i]) << endl;
	//}
	const int MAXIND = 4;
	string temp;
	Patiant arrayOfPatients[MAXIND];
	for (int i = 0; i < MAXIND; i++){
		cout << "Enter height in centimetres: ";
		cin >> arrayOfPatients[i].height;
		cout << "Enter weight in kilograms: ";
		cin >> arrayOfPatients[i].weight;
		cout << "Enter age: ";
		cin >> arrayOfPatients[i].age;
		cout << "male or female (m/f): ";
		cin >> temp;
		if (temp == "m"){
			arrayOfPatients[i].isMale = true;
		}
		else{
			arrayOfPatients[i].isMale = false;
		}
	}
	string gender;
	for (int i = 0; i < MAXIND; i++){
		cout << "Patient " << i + 1 << endl;
		float bmi = arrayOfPatients[i].weight / pow(arrayOfPatients[i].height, 2);
		cout << "BMI: " << bmi << endl;
		cout << "Age: " << arrayOfPatients[i].age << endl;
		if (arrayOfPatients[i].isMale == true){
			gender = "male";
		}
		else{
			gender = "female";
		}
		cout << "Gender:" << gender << endl;
	}
	return 0;
}

double PointlessFunction(Simple ArbitraryParameter)
{
	// this pointless function is purely to show how to access elements of a struct passed as a parameter
	return (ArbitraryParameter.Element1+ArbitraryParameter.Element2);
}
