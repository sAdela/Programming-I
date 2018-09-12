/*

Make a program that will allow user to input number n (10 <= n <= 1000). Then simulate input of n random numbers. 
Calculate statistic data -> in which percent of n generated random numbers do prime number shows up.

*/


#include<iostream>
#include<ctime>
#include<cmath>
#include<iomanip>
using namespace std;

bool isPrime(int Num) {  //Optimized way to check a number is prime
	if (Num == 1) 
		return false;

	if (Num == 2 || Num == 3 || Num == 5 || Num == 7) 
		return true;

	if (Num % 2 == 0 || Num % 3 == 0 || Num % 5 == 0 || Num % 7 == 0 || Num % 9 == 0) 
		return false;

	for (int i = 6; i <= sqrt(Num); i += 5) 

		if (Num%i == 0) return false;
	

	return true;
}

void main() {

	int Num, counter = 0;

	do {

	cin >> Num;					
			
	} while (Num <= 10 || Num >= 10000);		// Limiting users input 

	int *Array = new int[Num];

	srand(time(NULL));


	for (int i = 0; i < Num; i++) {

		Array[i] = rand() % 1000 + 1;		//Simulating random input
		cout << Array[i] << " ";
		cout << endl;

		if (isPrime(Array[i]))			//Checking for primes
		counter++;

	}
	
	cout << setprecision(3) << (float(counter) / Num) * 100 << "%"; //Calculating frequency


	system("Pause>0");
}