#include <iostream>
#include "MyStack.h"

MyStack::MyStack() {
	size = 1;
	tos = 0;
	elements = new (nothrow) double[size];
	elements[0] = 0;
}

MyStack::MyStack(int _size) {
	size = _size;
	elements = new (nothrow) double[size];
	tos = 0;
	for (int i = 0; i <= _size - 1; i++) {
		elements[i] = 0;
	}
}

MyStack::MyStack(int _size, double *_tab) {
	size = _size;
	tos = 0;
	elements = new (nothrow) double[_size];
	for (int i = 0; i <= _size - 1; i++) {
		elements[i] = _tab[i];
		tos++;
	}
}

MyStack::MyStack(const MyStack& n)
{
	size = n.size;
	tos = n.tos;
	elements = new (nothrow) double[n.size];
	for (int i = 0; i < n.tos; i++)
		elements[i] = n.elements[i];

}

MyStack::~MyStack() {
	delete[]elements;
}

MyStack & MyStack::operator=(const MyStack &a) {
	if (this == &a) return *this;
	if (size != a.size) {
		delete[]elements;
		elements = new (nothrow) double[a.size];
	}
	size = a.size;
	tos = a.tos;
	for (int i = 0; i < a.tos; i++)
		elements[i] = a.elements[i];
	return *this;
}



bool MyStack::isEmpty() const {
	if (tos <= 0) return true;
	else return false;
}
bool MyStack::isFull() const {
	if (tos >= size) return true;
	else return false;
}
double MyStack::front() const {
	return elements[tos - 1];
}

bool MyStack::pop(double &n) {
	if (MyStack::isEmpty() == true) {
		return false;
	}
	else {
		n = elements[tos - 1];
		elements[tos - 1] = 0;
		tos--;
		return true;
	}
}
bool MyStack::push(double n) {
	if (MyStack::isFull() == true) {
		return false;
	}
	else {
		elements[tos] = n;
		tos++;
		return true;
	}
}

ostream &operator<<(ostream &os, const MyStack &st) {
	cout << "Stack have " << st.tos << "/" << st.size << ":[";
	for (int i = 0; i < st.tos; i++)
		cout << st.elements[i] << " ";
	cout << "]";
	return os;
}
MyStack & MyStack::operator++() {
	double *tmp = new double[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = elements[i];
	}
	tmp[size] = -1;
	size++;
	delete[] elements;
	elements = tmp;
	return *this;
}


MyStack operator+(MyStack a, MyStack b) {
	MyStack *tmp = new MyStack(a.tos + b.tos);
	double n;
	while (a.isEmpty() != true) {
		a.pop(n);
		tmp->push(n);
	}
	while (b.isEmpty() != true) {
		b.pop(n);
		tmp->push(n);
	}
	return *tmp;
}

MyStack operator--(MyStack &s, int n) {
	MyStack old(s);
	s.elements[s.tos - 1] = 0;
	s.tos--;
	return old;
}
