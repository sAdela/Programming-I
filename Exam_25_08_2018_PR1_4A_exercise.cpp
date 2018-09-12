/*

Given the 2D array which simulates chess table, you have to enable input of integers such that every 'black' field is entered by even number
with odd digits number, and every 'white' field is entered by odd number with even digits number. Check if the matrix is symmetrical by the main diagonal
and if it is, transpose the matrix by replacing the rows with colonies. If it's not fully symmetrical, print how much symmetrical elements there are.

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

void Input(int Array[][8]) {

	srand(time(0));
	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {

				do {
				//	cin >> Array[i][j];		// For easier testing: Array[i][j] = rand() % 2000 + 1;
					Array[i][j] = rand() % 2000 + 1;
				} while (Array[i][j] % 2 != 0 || countDigits(Array[i][j]) % 2 == 0);	//Satisfying input conditions

			}
			else {

				do {
					//cin >> Array[i][j];		// For easier testing: Array[i][j] = rand() % 2000 + 1;
					Array[i][j] = rand() % 2000 + 1;
				} while (Array[i][j] % 2 == 0 || countDigits(Array[i][j]) % 2 != 0);	 //Satisfying input conditions

			}


		}
	}
}


bool isSymmetrical(int Array[][8]) { // To check whether matrix array is symmetrical
	bool flag = true;
	int counter = 0;
	for (int i = 0; i < 8; i++)

		for (int j = 0; j < 8; j++)

			if (Array[i][j] != Array[j][i]) {

				flag = false;
				counter++;
			}
	if (flag == false)
		cout << "There are " << 64 - counter - 8 << " symmetrical elements!" << endl;

	return flag;
}

void Transpose(int Array[][8]) {  //Optimized way to transponse matrix
	int temp;
	for (int i = 0; i < 8; i++)

		for (int j = 0; j < 8; j++)

			if (i != j && i < j) {
				temp = Array[i][j];
				Array[i][j] = Array[j][i];
				Array[j][i] = temp;
			}

}

void main() {

	int Array[8][8] = { 0 };

	Input(Array);

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++)

			cout << setw(5) << Array[i][j] << " ";
		cout << endl;
	}

	if (isSymmetrical(Array))
		Transpose(Array);


	cout << endl << endl;


	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++)

			cout << setw(5) << Array[i][j] << " ";
		cout << endl;
	}

	system("Pause>0");
}