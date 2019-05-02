#include <iostream>
#include <string>
#include "Person.h"
#include "SortedPersonList.h"

using namespace std;

// Function Trim returns string s with removed leading and ending spaces
string Trim(string s) {
	int f = s.find_first_not_of(' ');
	if (f == string::npos) return string();
	int l = s.find_last_not_of(' ');
	return s.substr(f, l - f + 1);
}

int main() {
	Person persons[] = { Person("Wojciech","Kowalski","mini.pw.edu.pl"),
						 Person("John","Smith","microsoft.com"),
						 Person("Jan","Dzban","dzban.com.pl"),
						 Person("Thomas","Brown","oracle.com"),
						 Person("Janina","Jankowska-Nowak","dobre.placki.com"),
						 Person("Adam","Kowalski","mini.pw.edu.pl"),
						 Person("Beata","Abacka","elka.pw.edu.pl"),
						 Person("Janusz","Nowak","microsoft.pl"),
						 Person("Jacek","Placek","bajki.pl"),
	};
	int persons_lenght = sizeof(persons) / sizeof(Person);
	cout << endl;

	// List all persons
	for (int i = 0; i < persons_lenght; ++i)
		cout << persons[i] << endl;
	cout << endl;

	// List all persons whose first names start with "Jan"
	for (int i = 0; i < persons_lenght; ++i)
		if (persons[i].GetFirstName().find("Jan") == 0)
			cout << persons[i] << endl;
	cout << endl;

	// List all persons whose last names contain letter 'N' or 'n'
	for (int i = 0; i < persons_lenght; ++i)
		if (persons[i].GetLastName().find_first_of("Nn") != string::npos)
			cout << persons[i] << endl;
	cout << endl;

	// List all persons whose emails ends with ".pl"
	for (int i = 0; i < persons_lenght; ++i)
		if (persons[i].GetMail().rfind(".pl") == persons[i].GetMail().length() - 3)
			cout << persons[i] << endl;
	cout << endl;

	// Tests for Trim function

	string s1("  Text with leading and ending spaces     ");
	cout << "#" << s1 << "#" << endl;
	cout << "#" << Trim(s1) << "#" << endl;

	string s2("Text   without   leading   and   ending   spaces");
	cout << "#" << s2 << "#" << endl;
	cout << "#" << Trim(s2) << "#" << endl;

	string s3(" ");
	cout << "#" << s3 << "#" << endl;
	cout << "#" << Trim(s3) << "#" << endl;

	string s4("                    ");
	cout << "#" << s4 << "#" << endl;
	cout << "#" << Trim(s4) << "#" << endl;

	string s5;
	cout << "#" << s5 << "#" << endl;
	cout << "#" << Trim(s5) << "#" << endl;

	cout << endl;

	// Tests for SortedPersonList class

	SortedPersonList list;
	cout << "# Empty list #" << endl;
	cout << list << endl;

	for (int i = 0; i < persons_lenght; ++i)
		list.Insert(persons[i]);
	cout << "# List #" << endl;
	cout << list << endl;

	SortedPersonList list2(list);
	list.GetFirst();
	list.GetFirst();
	cout << "# List #" << endl;
	cout << list << endl;
	cout << "# List 2 #" << endl;
	cout << list2 << endl;

	SortedPersonList list3;
	list3 = list;
	list.GetFirst();
	list.GetFirst();
	cout << "# List #" << endl;
	cout << list << endl;
	cout << "# List 3 #" << endl;
	cout << list3 << endl;

	system("pause");

	return 0;
}


