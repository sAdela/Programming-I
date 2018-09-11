#include<iostream>
using namespace std;

int FindFactorial(int Num) {
								
	int factorial = 1;		//Factorial of number is product of all positive integers less than or equal to that number ( 4! = 1*2*3*4 )

	for (int i = 1; i <= Num; i++) 

		factorial *= i;  
	

	return factorial;
}

void main() {

	int Num;
	float Sum = 0;

	cout << "Insert number: ";

	cin >> Num;

	for (int i = 0; i < Num; i++) {

		Sum += pow(-1, i + 2) * float(i + 1) / ((Num - i) + FindFactorial(i + 1));

	}
	cout << "Sum: " << Sum << endl;



	system("pause>0");
}