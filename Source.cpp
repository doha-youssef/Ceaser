#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
string encrypt(string plainText, int key)
{
	string cipherText = "";
	for (int i = 0; i < plainText.length(); i++)
	{
		if (plainText[i] >= 'A' && plainText[i] <= 'Z')
		{
			plainText[i] += 32;
		}
		if (plainText[i] >= 'a' && plainText[i] <= 'z')
		{
			int p = plainText[i] - 'a';
			int c = (p + key) % 26;
			cipherText += (c + 'a') - 32;
		}
	}
	return cipherText;
}
string decrypt(string cipherText, int key)
{
	string plainText = "";
	for (int i = 0; i < cipherText.length(); i++)
	{
		cipherText[i] += 32;
		int c = cipherText[i] - 'a';
		int p = ((c - (key % 26)) + 26) % 26;
		plainText += (p + 'a');
	}
	return plainText;
}
int main()
{
	char y;
	do
	{
		cout << "Do you want to do encryption or decryption? ";
		string operation; cin >> operation;
		if (operation == "encryption")
		{
			cout << "please enter the text you want to encrypt: ";
			cin.ignore();
			string plainText;
			getline(cin, plainText);
			cout << "please enter the key: ";
			int key; cin >> key;
			cout << encrypt(plainText, key) << endl;
			cout << "Do you want to do another operation?(y|n):";
			cin >> y;
		}
		else if (operation == "decryption")
		{
			cout << "please enter the text you want to decrypt: ";
			string cipherText;
			cin >> cipherText;
			cout << "please enter the key: ";
			int key;
			cin >> key;
			cout << decrypt(cipherText, key) << endl;
			cout << "Do you want to do another operation?(y|n):";
			cin >> y;
		}
	} while (y != 'n');
}