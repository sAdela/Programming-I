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
					cin >> Array[i][j];		// For easier testing: Array[i][j] = rand() % 2000 + 1;
				} while (Array[i][j] % 2 != 0 || countDigits(Array[i][j]) % 2 == 0);	//Satisfying input conditions

			}
			else {

				do {
					cin >> Array[i][j];		// For easier testing: Array[i][j] = rand() % 2000 + 1;
				} while (Array[i][j] % 2 == 0 || countDigits(Array[i][j]) % 2 != 0);	 //Satisfying input conditions

			}


		}
	}
}


bool isSymmetrical(int Array[][8]) { // To check whether matrix array is symmetrical
	bool flag = true;

	for (int i = 0; i < 8; i++)

		for (int j = 0; j < 8; j++)

			if (Array[i][j] != Array[j][i])

				flag = false;


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