/*

Given the 2D array which simulates chess table, you have to enable input of integers such that every 'black' field is entered by even number
with odd digits number, and every 'white' field is entered by odd number with even digits number. Check if the matrix is symmetrical by the main diagonal
and if it is, function return index of row with highest average of elements, and if it's not fully symmetrical, then function return index of 
column with the smallest average of elements.

*/

#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;

int countDigits(int Num) { //To count how many digits number have
	int counter = 0;

	while (Num > 0) {
		Num /= 10;
		counter++;
	}

	return counter;
}
bool InputConditions(int i, int j) {

	if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0) == true)

		return true;

	return false;
}

void Input(int Array[][8]) {

	srand(time(0));

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			if (InputConditions(i,j) == true) {

				do {
					//			cin >> Array[i][j];		 For easier testing:
					Array[i][j] = rand() % 2000 + 1;

				} while (Array[i][j] % 2 != 0 || countDigits(Array[i][j]) % 2 == 0);	//Satisfying input conditions

			}
			else {

				do {
							//cin >> Array[i][j];		 For easier testing:
					Array[i][j] = rand() % 2000 + 1;

				} while (Array[i][j] % 2 == 0 || countDigits(Array[i][j]) % 2 != 0);	 //Satisfying input conditions

			}


		}
	}
}

bool isSymmetrical(int Array[][8]) { // To check whether matrix array is symmetrical
	int counter = 0;
	for (int i = 0; i < 8; i++)

		for (int j = 0; j < 8; j++)

			if (Array[i][j] != Array[j][i]) 

				return false;
				
			
	return true;
}

float Average(int Array[][8], bool Symmetrical) {
	float Sum = 0;
	int Index = 0;

	if (Symmetrical == true) {
		int Max = 0;
		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 8; j++) {

				Sum += Array[i][j];
			}
			if (Sum > Max) {

				Max = Sum;
				Index = i;

			}
			Sum = 0;
		}

	}
	else {
		
		int Max = 100000;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				Sum += Array[j][i];
			
			}
			cout << Sum << " FOR " << i << " row" << endl;
			if (Sum < Max) {

				Max = Sum;
				Index = i;
			}
			Sum = 0;


		}

	}
	return Index;
}

void main() {

	int Array[8][8] = { 0 };

	Input(Array);

	if (isSymmetrical(Array))
		cout << Average(Array, true) << endl;
	else
		cout << Average(Array, false) << endl;

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++)
			cout << setw(5) << Array[i][j];
		cout << endl;

	}


	system("Pause>0");
}