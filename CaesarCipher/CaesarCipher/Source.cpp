#include <iostream>
#include <string>

using namespace std;

string Cipher(string theString, int key,
	bool encrypt);

void text(string theString, int key, bool encrypt);

int main() {

	string message;
	int key;
	bool encryption;

	cout << "Enter a string that you wish to encrypt: " << endl;
	
	getline(std::cin, message);

	cout << "By how many letters your message should be shifted?" << endl;
	cin >> key;


	while (1) {
		cout << "Do you wish to encrypt or decrypt your message ? \n enter 1 (encryption) \n or 0 (decryption)" << endl;
		cin >> encryption;

		text(message, key, encryption);
	}

	return 0;
}

string Cipher(string theString, int key, bool encrypt) {
	string returnString = "";
	int charCode = 0;
	char letter;

	if (encrypt) {
		key = key * -1;
	}

	string::iterator it;
	int index = 0;

	for (it = theString.begin(); it < theString.end(); it++, index++){

		if (isalpha(theString[index])){

			// Conver char to ASCII int 
			charCode = (int)theString[index];

			// Move to another ASCII table value based on the key
			charCode += key;

			// If uppercase check if the new character code >
			// char code for Z, or < char code for A
			// If so shift the character code so that its value
			// wraps back into the letter character codes
			if (isupper(theString[index])) {

				if (charCode > (int)'Z') {
					charCode -= 26;
				}
				else if (charCode < (int)'A') {
					charCode += 26;
				}
			}
			else {

				// Do the same for lowercase letters
				if (charCode > (int)'z') {
					charCode -= 26;
				}
				else if (charCode < (int)'a') {
					charCode += 26;
				}

			}

			// Convert from int to char and add the returning string
			letter = charCode;
			returnString += letter;

		}
		else {
			letter = theString[index];
			returnString += theString[index];
			cout << theString[index] << "\n";
		}

	}

	return returnString;
}


void text(string theString, int key, bool encrypt) {

	if (encrypt) {
		string encryptedStr = Cipher(theString, key, true);
		cout << "Your message has been encrypted: " << encryptedStr << "\n";
	}

	else {
		string decryptedStr = Cipher(theString, key, false);
		cout << "Your message has been decrypted: " << decryptedStr << "\n";
	}
}