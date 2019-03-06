#include <iostream>

using namespace std;

int computeXOR(int n);
void convertToBinary(unsigned int n);
void printArray(int * a, int size);

int main() {
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof a / sizeof a[0];
	
	for (int i = 0; i < n; i++) {
		cout << "IN DECIMAL:" << endl;
		cout << "XOR of " << a[i] << " is " << computeXOR(a[i]) << endl;
		cout << endl;
		cout << "IN BINARY:" << endl;

		cout << "XOR of ";
		convertToBinary(a[i]);
		cout << " is "; 
		convertToBinary(computeXOR(a[i]));
		cout << endl << endl;
	}
	system("PAUSE");
	return 0;
}

int computeXOR(int n) {
	if (n % 4 == 0)
		return n;
	if (n % 4 == 1)
		return 1;
	if (n % 4 == 2)
		return n + 1;
	else
		return 0;
}

void convertToBinary(unsigned int n) {
    if (n / 2 != 0) {
        convertToBinary(n / 2);
    }
	cout << n % 2;
}

void printArray(int * a, int size){
	int i;

	for (i = 0; i < size; i++){
		cout << a[i];
	}
}

