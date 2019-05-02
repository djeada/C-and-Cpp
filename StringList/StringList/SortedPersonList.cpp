#include <iostream>
#include "Person.h"
#include "SortedPersonList.h"

using namespace std;

SortedPersonList::SortedPersonList() {
	head = nullptr;
}

SortedPersonList::SortedPersonList(const SortedPersonList& spl) {
	if (spl.head == nullptr) {
		head = nullptr;
		return;
	}
	head = new Element(spl.head->person, nullptr);
	Element *ptr = head;
	Element *splptr = spl.head->next;
	while (splptr != nullptr) {
		ptr->next = new Element(splptr->person, nullptr);
		ptr = ptr->next;
		splptr = splptr->next;
	}
}

SortedPersonList::~SortedPersonList() {
	Element *ptr = head;
	while (ptr != nullptr)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}
}

SortedPersonList& SortedPersonList::operator=(const SortedPersonList& spl) {
	if (this == &spl) return *this;
	this->~SortedPersonList();
	if (spl.head == nullptr)
	{
		head = nullptr;
		return *this;
	}
	head = new Element(spl.head->person, nullptr);
	Element *ptr = head;
	Element *splptr = spl.head->next;
	while (splptr != nullptr) {
		ptr->next = new Element(splptr->person, nullptr);
		ptr = ptr->next;
		splptr = splptr->next;
	}
	return *this;
}

// Wersja alternatywna - fajniejsza
// Ale studentom to jej raczej nie pokazujemy
//
//SortedPersonList& SortedPersonList::operator=(const SortedPersonList& spl)
//    {
//    if ( this==&spl ) return *this;
//    this->~SortedPersonList();
//    SortedPersonList tmp(spl);
//    head=tmp.head;
//    tmp.head=nullptr;
//    return *this;
//    }

Person SortedPersonList::GetFirst() {
	Person p;
	Element *ptr;
	if (head == nullptr) return p;
	p = head->person;
	ptr = head;
	head = head->next;
	delete ptr;
	return p;
}

void SortedPersonList::Insert(const Person& p) {
	if (head == nullptr || p < head->person)
		head = new Element(p, head);
	else {
		Element *ptr = head;
		while (ptr->next != nullptr && ptr->next->person < p) ptr = ptr->next;
		ptr->next = new Element(p, ptr->next);
	}
}

ostream& operator<<(ostream& os, const SortedPersonList& spl) {
	for (SortedPersonList::Element *ptr = spl.head; ptr != nullptr; ptr = ptr->next)
		os << ptr->person << endl;
	return os;
}
