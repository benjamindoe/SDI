// Session2.cpp : Defines the entry point for the console application.
// Program to test "if else"

#include "stdafx.h"
#include "math.h"
#include <Windows.h>
//the follwing 2 lines are necessary to include the library for displaying to a console window
#include <iostream>
using namespace std;

//this is the start of the main function. Note that I have used a simpler version than in last week's lab.
//The version last week is part of the way to allow for unicode

int main(){
	/*int aInt = 5;			//note the semicolon!
	float bFloat = 3.6;
	//you will add assignment statements here
	aInt = 200;
	aInt = 10;
	// you will add the if/else here
	if (aInt < 10){
		cout << "Too low" << endl;
	}
	else if (aInt == 10){
		cout << "Perfect" << endl;
	}
	else{
		cout << "Too high" << endl;
	}
	if (bFloat == 3.6)
	{
		cout << " Hooray 3.6 found" << endl;
	}
	int a = 2;
	int b = 4;
	int c = 6;
	int d = 8;
	if (a == 2 && b < 3){
		cout << "Test A" << endl;
	}
	else if (a != 2 && b > 2){
		cout << "Test B" << endl;
	}
	else if (c < 7 || d > 9){
		cout << "Test C" << endl;
	}
	else if (c >= 6 || d <= 10){
		cout << "Test D" << endl;
	}
	else{
		cout << "Whoops!" << endl;
	}
	
	float bmi, height, weight;
	cout << "Please enter height in metres : ";
	cin >> height;
	cout <<"Please enter weight in kilograms : ";
	cin >> weight;
	bmi = weight / pow(1.8, 2);
	if (bmi < 12){
		cout << "Underweight" << endl;
	}
	else if (bmi > 25){
		cout << "Overweight" << endl;
	}
	else{
		cout << "Practically Perfect" << endl;
	}*/
	
	/*
	//Rock Paper Scissors
	int player1, player2;
	cout << "1 - Scissors \n"
			"2 - Paper \n"
			"3 - Rock \n"
			"0 - Quit \n";
	cout << "Player 1: ";
	cin >> player1;
	cout << "Player 2: ";
	player2 = rand() % 3;
	//while (player1 != 0 && player2 != 0){
	//	if (player1 == 1 && player2 == 2 || player1 == 2 && player2 == 3 || player1 == 3 && player2 == 1){
	//		cout << "Player 1 is the winner" << endl;
	//	}
	//	else if (player1 == player2){
	//		cout << "It is a draw" << endl;

	//	}
	//	else{
	//		cout << "Player 2 is the winner" << endl;
	//	}
	switch (player1 - player2){
		case -1:
		case 2:
			cout << "Player 1 is the winner"<<endl;
			break;
		case 0:
			cout << "We have a draw" << endl;
			break;
		case 1:
		case -2:
			cout << "Player 2 is the winnder" << endl;
			break;
		}
		cout << "\n1 - Scissors \n"
				"2 - Paper \n"
				"3 - Rock \n"
				"0 - Quit \n";
		cout << "Player 1: ";
		cin >> player1;
		cout << "Player 2: ";
		cin >> player2;
	}*/
	/*
	for (int i = 10; i != 0; i--){
		cout << i <<endl;
		Sleep(2000);
	}
	cout << "Thunderbirds are go" << endl;
	cout<<"This is the end of the program Bye"<<endl;
	

	*/
	/*float gramsPerOunce = 28.35;
	double ounce, gram;
	cout << "Please enter the number of ounces: ";
	cin >> ounce;
	gram = gramsPerOunce * ounce;
	cout << "Grams: " << gram<<endl;
	cout << " ---------------- \n"
			"| Grams | Ounces |"<<endl;
	for (int i = 0; i <= 10; i++){
		gram = gramsPerOunce*i;
		cout << "|       |        |\n";
		cout <<"|   "<< i << "   | " << gram <<" |"<<endl;
	}*/
	/*double pound, poundPerDollar;
	cout << "Please enter the currency exchange rate for pounds per dollar: ";
	cin >> poundPerDollar;
	cout << " ---------------- \n"
			"| Dollar | Pound |" << endl;
	for (int dollar = 0; dollar <= 20; dollar++){
		pound = poundPerDollar*dollar;
		if (pound > 10){
			break;
		}
		cout << "|       |        |\n";
		cout << "|   " << dollar << "   |  " << pound << "  |" << endl;
	}*/
	/*int userInt = 1;
	while (userInt != 0){
		cout << "Enter an integer: ";
		cin >> userInt;
		cout << endl << "Times table for " << userInt << endl;
		for (int i = 0; i <= 10; i++){
			cout << i << " " << i * userInt << endl;
		}
	}*/
	/*int age = 0;
	while (age < 18 || age > 40){
		cout << "Input age between 18 and 40: ";
		cin >> age;
	}
	cout << endl;
	for (int i = 10; i <= 50; i += 10){
		cout << age + i<<endl;
	}*/
	//Rock Paper Scissors
	int player1, player2;
	cout << "1 - Scissors \n"
	"2 - Paper \n"
	"3 - Rock \n"
	"4 - Lizard \n"
	"5 - Spock \n"
	"0 - Quit \n";
	cout << "Player 1: ";
	cin >> player1;
	cout << "Player 2: ";
	cin >> player2;
	while (player1 != 0 && player2 != 0){
		switch (player1 - player2){
		case -3:
		case -1:
		case 2:
		case 4:
			cout << "Player 1 is the winner" << endl;
			break;
		case 0:
			cout << "We have a draw" << endl;
			break;
		case 1:
		case 3:
		case -2:
		case -4:
			cout << "Player 2 is the winnder" << endl;
			break;
		}
		cout << "\n1 - Scissors \n"
		"2 - Paper \n"
		"3 - Rock \n"
		"4 - Lizard \n"
		"5 - Spock \n"
		"0 - Quit \n";
		cout << "Player 1: ";
		cin >> player1;
		cout << "Player 2: ";
		cin >> player2;
	}
	return 0;
}

