/*

Make a program that loads a natural number n. Program should print the smallest natural number m,
bigger or equal n, which is potential of some other natural number ( m = k^i )

*/


#include<iostream>
using namespace std;


int isItPotential(int Num) {

	int Nearest = 100000, optimize;

	if (Num == 1) return Num;     // To optimize, so I don't have to have bigger number of FOR loops (those that would start from 1)

	for (int i = 2; i < 30; i++) {

		for (int j = 2; j < 30; j++) {

			optimize = pow(i, j);		// Variable to make less number of calculation (if I didn't use it, I would have to calculate it 3 times per loop)

			if (optimize == Num) return Num; //Optimizing again, so I don't have to do all that comparations in next IF condition, rather return instantly

			if (optimize > Num && optimize < Nearest ) {    //Find nearest bigger potential of number

				Nearest = optimize;
				break;						//It would be nonsense if I continue this (if I find 2^3 is bigger than my number, it's for sure smaller than 2^4, so I break it immediately) - optimize
			}
			
		}

	}
	return Nearest;
}

void main() {

	int Num;
	bool variable = false;

	cout << "Insert number: ";
	cin >> Num;

	cout << isItPotential(Num) << endl;
	

	system("Pause>0");
}