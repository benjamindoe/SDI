#include "stdafx.h"
#include <string>
#include <iostream>
#define MODULEINDEX 12
using namespace std;
int GetMark(int ModuleIndex);
int AvMark(int moduleMarks[]);
int main(){
	float average = 0;
	bool isPassed;
	int gradeCount[5] = { 0, 0, 0, 0, 0 };
	string grade;
	int moduleMarks[MODULEINDEX];
	for (int i = 0; i < MODULEINDEX; i++){
		moduleMarks[i] = GetMark(i);
		if (moduleMarks[i] > 40){
			isPassed = true;
			if (moduleMarks[i] > 70){
				gradeCount[0]++;
			}
			else if (moduleMarks[i] > 60){
				gradeCount[1]++;
			}
			else if (moduleMarks[i] > 50){
				gradeCount[2]++;
			}
			else if (moduleMarks[i] > 40){
				gradeCount[3]++;
			}
			else{
				gradeCount[4]++;
			}
		}
		average += moduleMarks[i];
	}
	average /= MODULEINDEX;
	if (average > 40){
		isPassed = true;
		if (average > 70){
			grade = '1st';
		}
		else if (average > 60){
			grade = '2i';
		}
		else if (average > 50){
			grade = '2ii';
		}
		else if (average > 40){
			grade = '3rd';
		}
	}
	if (isPassed){
		for (int i = 0; i < MODULEINDEX; i++){
			if (moduleMarks[i] < 35 && isPassed){
				grade = "Referred in module " + to_string(i);
				isPassed = false;
			} else if (moduleMarks[i] < 35 && !isPassed){
				grade += "\nReferred in module " + to_string(i)+"\n";
			}
		}
	}
	cout << "You have had " << to_string(gradeCount[0]) << " 1st, " << to_string(gradeCount[1]) << " 2i, " << to_string(gradeCount[2]) << " 2ii, " << to_string(gradeCount[3]) << " 3rd and " << to_string(gradeCount[4]) << "Fail marks.";
	cout << grade << endl;
	return 0;
}
int GetMark(int ModuleIndex){
	int temp;
	cout << "Enter mark for module " << ModuleIndex << ": ";
	cin >> temp;
	if (temp > 100 || temp < 0){
		cout << "Please input a sensible mark." << endl;;
		temp = GetMark(ModuleIndex);
	}
	return temp;
}
int AvMark(int moduleMarks[]){
	double average = 0;
	for (int i = 0; i < MODULEINDEX; i++){
		average += moduleMarks[i];
		cout << "Current score: " << moduleMarks[i];
		if (moduleMarks[i] < 20){
			moduleMarks[i] = 30;
			cout << "Score Modified: " << moduleMarks[i];
		}
	}
	average /= MODULEINDEX;
	return average;
}