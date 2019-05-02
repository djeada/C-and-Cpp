#ifndef __SortedPersonList_H__
#define __SortedPersonList_H__

#include <iostream>
#include "Person.h"

using namespace std;

class SortedPersonList {
	struct Element {
		Person person;
		Element *next;
		Element(const Person& p, Element *n) { person = p; next = n; }
	};
	Element *head;
public:
	SortedPersonList();
	SortedPersonList(const SortedPersonList& spl);
	~SortedPersonList();
	SortedPersonList& operator=(const SortedPersonList& spl);
	Person GetFirst();
	void Insert(const Person& p);
	friend ostream& operator<<(ostream& os, const SortedPersonList& spl);
};

#endif