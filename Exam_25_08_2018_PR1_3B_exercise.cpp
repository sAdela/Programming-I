/*

Make a program that will generate Fibonacci array and put him into 1D array consisting of 20 elements.
(Fibonacci array is array of numbers that starts with numbers 0 and 1, but every following number in array 
is obtained from summing last two members of array. 
Then make a function that will sort array in ascending order by middle digit. 
(For numbers with even number of digits use arithmetic average of two middle digits).

*/



#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


int countDigits(int Num) {		//Function to count how much digits do number have
	int counter = 0;
	if (Num == 0) return 1;

	while (Num > 0) {

		Num /= 10;    //I'm dividing it with 10, to remove last digit everytime, until it reach 0. With every step I increase counter of digits (it starts from 0)
		counter++;

	}

	return counter;
}

float average(int Num) {
	int temp = 0;
	int optim = countDigits(Num); //By declaring this variable, I optimize program so it don't have to calculate it everytime I need it in this function

	if (optim % 2 != 0)  // If number of digits isn't even number

		return Num / int(pow(10, int(optim / 2))) % 10;    // I'm dividing number with 10^(number of digits/2) and then mod 10 to get middle digit
	 
	else {   //Otherwise it's even, so I find two middle digits (for number 1234 it would be 23), and then calculate average of them

		int first = 0, second = 0;
		float averageDigit = 0;
		first = Num / int(pow(10, optim / 2)) % 10;
		second = Num / int(pow(10, int(optim / 2 - 1))) % 10;
		averageDigit = (first + second) / 2.0;

		return averageDigit;

	}


}


void Sort(int *Fibonacci) {  //Performing optimized bubble sort

	bool Change = true;
	int Temp = 0;

	while (Change == true) { 
		Change = false;

		for (int i = 0; i < 19; i++) {

			if (average(Fibonacci[i]) > average(Fibonacci[i + 1])) { // Sort in ascending order by middle digits
				Change = true;
				Temp = Fibonacci[i];
				Fibonacci[i] = Fibonacci[i + 1];
				Fibonacci[i + 1] = Temp;
			}

		}
	}

}

void main() {

	int Fibonacci[20] = { 0,1 }; //Fibonacci array is an array such that every member of array is sum of the last two members (0,1,1,2,3,5,8,13,21,...)


	for (int i = 2; i < 20; i++) {

		Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2]; //Generating Fibonacci array 

		

	}
	for (int i=0; i<20; i++)
		cout << Fibonacci[i] << " ";  //That's first 20 members of Fibonacci array! :)
	cout << endl;

	Sort(Fibonacci);  //Sorting Fibonacci array in ascending order by middle digit(s)


	for (int i = 0; i < 20; i++)
		cout << setw(5) << Fibonacci[i] << " ----> " << average(Fibonacci[i]) << endl; // It's how it looks like after sorting


	system("Pause>0");
}