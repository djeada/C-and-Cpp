// Struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student {
	string name;
	string dorm;
};

int main(){
	//Alocate space for students
	int enrollment; 
	cout << ("Enrollment: ") << endl;
	cin >> enrollment;

	student* students = new student[enrollment];

	//Prompt for students' names and dorms
	for (int i = 0; i < enrollment; i++) {
		cout << ("Name: ") << endl;
		cin >> students[i].name;
		cout << ("Dorm: ") << endl;
		cin >> students[i].dorm;
	}
	//Print students' names and dorms
	for (int i = 0; i < enrollment; i++) {
		cout << students[i].name << " is in " << students[i].dorm << endl;
	}

	// Save students to disk
	ofstream myfile;
	myfile.open("students.csv");
	for (int i = 0; i < enrollment; i++){
		myfile << students[i].name << ";" << students[i].dorm << endl;
	}	
	myfile.close();

	return 0;
}