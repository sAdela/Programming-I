#include<iostream>
#include<iomanip>
using namespace std;

int countDigits(int Num) { // Count how many digits number have
	int counter = 0;
	while (Num > 0) {
		Num /= 10;
		counter++;
	}

	return counter;
}

void Replace(int &Num1, int &Num2) {  //Replace two numbers
	int Temp;
	Temp = Num1; 
	Num1 = Num2;
	Num2 = Temp;

}

void Sort(int Array[], char character) { //Sorting depending on input (char)

	bool Change = true;
	int temp = 0;

	if (toupper(character) != 'A' && toupper(character) != 'D') {
		cout << "Sorting undefined! ";
		return;
	}
	

	while (Change == true) {

		Change = false;

		for (int i = 0; i < 19; i++) {

			if (toupper(character) == 'A' && Array[i] > Array[i + 1]) {

				Change = true;
				Replace(Array[i], Array[i + 1]);
			}

			else if (toupper(character) == 'D' && Array[i] < Array[i+1]){

				Change = true;
				Replace(Array[i], Array[i + 1]);

			}
		}
	}
}

void main() {

	int Array[20] = {};
	char character;

	for (int i = 0; i < 20; i++) {

		do {
			cin >> Array[i];
		} while (Array[i] < 100 || countDigits(Array[i]) % 2 == 0); //To satisfy condition of input

	}

	cout << "If you want to sort the array in ascending order type A, or for descending order D: ";
	cin >> character;

	Sort(Array, character);

	for (int i = 0; i < 20; i++)
		cout << setw(5) << Array[i];


	system("pause>0");
}