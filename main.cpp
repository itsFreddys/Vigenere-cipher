#include <iostream>
#include <string>
using namespace std;
string text;
string key;

void exitPrompt();

void uppercase(string& text, string& key);

string encryption(string& text, string& key);

string decryption(string text, string key);

string userInput();

int main()
{
	int choice = 0;
	string quiting;

	do
	{
		cout << "___________________________"
			<< "_______________________\n";
		cout << "Enter 1 to encrypt or 2 "
			<< "to decrypt your plaintext" << endl;
		cout << "* * * Only enter integer values * * *\n";
		cout << "1) Encrypt\n";
		cout << "2) Decrypt\n";
		cout << "3) Quit\n";
		cout << "User Choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "\nEncryption" << "\n-----------";
			userInput();

			cout << encryption(text, key) << endl;

		}
		else if (choice == 2) {
			cout << "\nDecryption" << "\n-----------";
			userInput();

			cout << decryption(text, key) << endl;
		}
		else if (choice == 3)
		{
			exitPrompt();
		}
		else
		{
			cout << "\nERROR\n" << "-------";
			cout << "\nIncorrect choice, try again.\n";
		}

	} while (choice != 3);
}

void exitPrompt()
{
	string quiting;

	cout << "\nAre you sure you want to exit the program?\n"
		<< "Type yes to exit or no to stay\n";
	cin >> quiting;
	if (quiting == "yes" || quiting == "YES")
	{
		cout << "\nSee you later Alligator\n\n";
	}
	else if (quiting == "no" || quiting == "NO")
		main();
	else
		cout << "\t\nError, neither yes or no, exiting program now\n\n\n";
}

void uppercase(string& text, string& key) {
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = toupper(text[i]);
	}
	for (int i = 0; i < key.length(); i++)
	{
		key[i] = toupper(key[i]);
	}
}

string encryption(string& text, string& key)
{	// encryption phase with shift n
	//En(x) = (x + n) mod 26 + 65('A')

	string result;

	for (int i = 0; i < text.length(); i) {

		for (int j = 0; j < key.length(); j++, i++) {
			result += char((int(text[i] + key[j])) % 26 + 'A');

			cout << text[i] << " " << int(text[i]) << " " << key[j] << endl;

			if (result.length() == text.length())
				break;
		}
		if (result.length() == text.length())
			break;
	}
	return result;
}

string decryption(string text, string key)
{	// decryption phase with shift n
	//Dn(x) = ((x - n) + 26) mod 26 + 65
	string result;

	for (int i = 0; i < text.length(); i) {

		for (int j = 0; j < key.length(); j++, i++) {
			result += char((int(text[i] - key[j]) + 26) % 26 + 65);

			cout << int(text[i]) << " " << text[i] << " " << key[j] << endl;

			if (result.length() == text.length())
				break;
		}
		if (result.length() == text.length())
			break;
	}
	return result;
}

string userInput() {

	//ask for user plaintext and key
	cout << "\nEnter a plaintext: ";
	cin >> text;

	cout << "Enter a key: ";
	cin >> key;

	//uppercase inputted data			//figure out how to disclude option if uppercase already exists
	uppercase(text, key);

	return text, key;
}
