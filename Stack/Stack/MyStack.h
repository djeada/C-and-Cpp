#ifndef _MYSTACK_H_
#define _MYSTACK_H_
//#pragma once
#include <iostream>
using namespace std;

class MyStack
{
	double* elements; //array
	int size;
	int tos; //top of stack
public:
	MyStack();
	MyStack(int);
	MyStack(int, double*);
	MyStack(const MyStack&);
	~MyStack();

	/* Add copy constructor and assignment operator */
	MyStack &operator=(const MyStack &);

	double front() const;
	bool pop(double &);
	bool push(double);
	bool isEmpty() const;
	bool isFull() const;

	/* Add operators ++ and -- */
	MyStack& operator++();
	friend MyStack operator--(MyStack &, int);

	friend ostream & operator<<(ostream &os, const MyStack &st);
	friend MyStack operator+(MyStack a, MyStack b);

};
#endif //_MYSTACK_H_

