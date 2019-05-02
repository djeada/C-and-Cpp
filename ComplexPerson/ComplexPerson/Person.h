#include <iostream>
#include <string>

class Person
{
	string name;
	int age;

public:
	Person();
	Person(const string _name, int _age);

	friend bool operator<(const Person& p1, const Person& p2);
	friend ostream& operator<<(ostream&, const Person&);
};

void my_swap(Person &a, Person &b);
void Sort_array(Person *a, const int size);