#ifndef __Person_H__
#define __Person_H__

#include <string>
#include <iostream>

using namespace std;

class Person {
	string firstName;
	string lastName;
	string mail;
public:
	Person(string firstN = "???", string lastN = "???", string compamy = "???");
	string GetFirstName() { return firstName; }
	string GetLastName() { return lastName; }
	string GetMail() { return mail; }
	void SetMail(string m) { mail = m; }
	friend bool operator<(const Person& p1, const Person& p2);
	friend ostream& operator<<(ostream& os, const Person& p);
};

#endif