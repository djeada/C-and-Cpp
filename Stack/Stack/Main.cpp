#include <iostream>
#include "MyStack.h"

//stack project

using namespace std;

int main() {

	//part 1 2p

	cout << "---Part 1 ---" << endl;

	int stack_size = 6;

	double tmp, tab[] = { 1, 2, 4, 0, 2 };

	MyStack mst1 = MyStack(); //initialization - default constructor

	cout << mst1 << endl;

	MyStack mst2(sizeof(tab) / sizeof(double), tab);

	cout << mst2 << endl;

	MyStack *p = new MyStack(stack_size); //initialization

	cout << (*p) << endl;


	//part 2 1p

	cout << endl << "---Part 2 ---" << endl;

	p->push(4);
	p->push(4);
	p->push(4);
	p->push(5);
	p->push(1);
	p->push(6);

	cout << (*p) << endl;


	if (p->isFull()) cout << "Stack is FULL" << endl;


	cout << "Front of stack = " << p->front() << endl;

	if (p->isFull()) cout << "Stack is  FULL" << endl;

	p->pop(tmp);

	if (p->isFull()) cout << "Stack is  FULL" << endl;


	if (mst1.isEmpty()) cout << "Stack is empty" << endl;
	else cout << "Stack not empty. " << endl;

	mst1.push(tmp);

	if (mst1.isEmpty()) cout << "Stack is empty" << endl;
	else cout << "Stack not empty. " << mst1 << endl;



	//part 3 2p

	cout << endl << "---Part 3 ---" << endl;

	MyStack cst1(*p); //copy constructor

	cout << cst1 << endl;

	MyStack cst2;

	cst2 = mst2; //assignement

	cout << cst2 << endl;



	//part 4 1p

	cout << endl << "---Part 4 ---" << endl;

	cst2 = cst2 + *p;

	cout << cst2 << endl;


	++mst1;
	mst1.push(-1);

	cst2--;
	cst1 = mst1 + cst2;

	cout << cst1 << endl;


	while (!cst2.isEmpty())
	{
		cst2.pop(tmp);
	}

	delete p;

	cout << "Bye" << endl;

	system("pause");

	return 0;
}

