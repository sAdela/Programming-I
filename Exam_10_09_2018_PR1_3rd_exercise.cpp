
/*
Given an array of 20 elements, enable input of big and small letters.
Make a function that remove big letters from array and array is immediately moved to one place to the left, 
not at the end by removing all letters or when printing.
*/


#include<iostream>
using namespace std;

bool isBigLetter(char Char) {

	if (Char >= 'A' && Char <= 'Z') return true;

	return false;
}
int moveArray(char Array[], int i) {
	if (isBigLetter(Array[i]))
		i--;
	return i;
}

void main() {

	char Array[20] = { 0 };

	for (int i = 0; i < 20; i++) {

		do {

			cin >> Array[i];

		} while ((Array[i]<65 || Array[i] > 90) && (Array[i] < 90 || Array[i] > 122));

		i = moveArray(Array, i);

	}

	for (int i = 0; i < 20; i++)

		cout << Array[i] << " ";



	system("Pause>0");
}