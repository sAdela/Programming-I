/*

Peter wants to generate some prime numbers for his cryptosystem. Help him!
Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10).
In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000)
separated by a space.

*/


#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int Num) {  // Optimized solution of checking if a number is prime
	if (Num == 1) return false;
	if (Num == 2 || Num == 3 || Num == 5 || Num == 7) return true;

	if (Num % 2 == 0 || Num % 3 == 0 || Num % 5 == 0 || Num % 7 == 0 || Num % 9 == 0) return false;

	for (int i = 6; i <= sqrt(Num); i += 5) {
		if (Num%i == 0) return false;
	}
	return true;
}

int main() {

	int TestCases, a, b;
	cin >> TestCases; 


	for (int i = 0; i < TestCases; i++) {
		cin >> a >> b;   
		if (a > b) { // If first number is bigger than second number
			int temp = a; //I declare it here because in some cases, this might not be the case :) And to avoid unused variable :)
			a = b;
			b = temp;
		}
		for (int j = a; j <= b; j++) {
			if (isPrime(j) == true)
				cout << j << endl;
		}

	}

	system("pause>0");
	return 0;
}