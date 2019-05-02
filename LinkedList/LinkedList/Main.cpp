#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

int main() {

	List Adam;
	
	cout << "How many numbers you want babisiu?" << endl;
	
	int size = 0;
	cin >> size;

	int num = 0;

	while (size != 0) {
		cout << "Gibbme yo numba" << endl;
		cin >> num;
		Adam.AddNode(num);
		size--;
	}

	cout << "So that's your list: " << endl;
	Adam.PrintList();

	cout << "Enter something that you want to delete" << endl;
	cin >> num;
	Adam.DeleteNode(num);

	cout << "So that's your list: " << endl;
	Adam.PrintList();

	cout << endl << "Bye babisiu" << endl;
	system("pause");

	return 0;
}