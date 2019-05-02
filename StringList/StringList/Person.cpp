#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person(string firstN, string lastN, string company) {
	firstName = firstN;
	lastName = lastN;
	mail = firstName + "." + lastName + "@" + company;
}

bool operator<(const Person& p1, const Person& p2) {
	return p1.lastName < p2.lastName || (p1.lastName == p2.lastName && p1.firstName < p2.firstName);
}

ostream& operator<<(ostream& os, const Person& p) {
	return os << p.firstName << " " << p.lastName << ", " << p.mail;
}
