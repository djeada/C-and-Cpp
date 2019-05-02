#include <cstdlib>
#include <iostream>

#include "List.h"

using namespace std;

List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::AddNode(int addData) {
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
	else {
		head = n;
	}
}

void List::DeleteNode(int delData) {
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << delData << "was not found in the list";
		delete delPtr;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The value " << delData << "was deleted"; 
	}
}

bool List::isEmpty() {
	if (head == NULL)
		return 1;
	else
		return 0;
}

void List::PrintList() {
	curr = head;
	if (!isEmpty()) {
		while (curr != NULL) {
			cout << curr->data << endl;
			curr = curr->next;
		}
	}
}

void List::Search(nodePtr Ptr, int value) {
	if (Ptr == NULL) {
		cout << value << " was not found" << endl;
	}
	else if (Ptr->data == value) {
		cout << value << " was found" << endl;
	}
	else {
		Search(Ptr->next, value);
	}
}
