/*

Make a program that simulates throwing three cubes (one cube have 6 sides and on that sides are numbers 1-6)
Simulate constantly throwing all three cubes until in two rows repeatedly happen to get same numbers on all
three cubes (for example, in sixth throwing you get 2,2,2 and in seventh 4,4,4 on all three cubes)
Print how much throwing there were until above condition didn't happen.

*/


#include<iostream>
#include<ctime>
using namespace std;

void main() {

	int Array[6] = { 0 };     // Array to keep track of last 6 throws
	int counter = 0;
	bool first = false, second = false, flag = false;; // For first 3 and second 3 same throws

	srand(time(0));

	while (first == false || second == false) {

		first = false; second = false, flag = false;

		for (int i = 0; i < 3; i++)    //Three random throws

			Array[i] = rand() % 6 + 1;

		counter++;

		if (Array[0] == Array[1] && Array[1] == Array[2])  //Only if first three throws were same, second three throws will happen

			for (int i = 3; i < 6; i++) {

				Array[i] = rand() % 6 + 1;
				flag = true;
			}

		if (flag == true) counter++;


		if (Array[3] != 0) {				// To optimize, only if second throw happened, I will check if it were same numbers
			if (Array[3] == Array[4] && Array[4] == Array[5]) {

				first = true;				// and put both on true. That will end WHILE loop
				second = true;

			}
		}
	}


	for (int i = 0; i < 6; i++)				// And therefore, I print my array :)

		cout << Array[i] << " ";
	cout << endl;
	cout << "We got that in " << counter << " throwing" << endl;



	system("Pause>0");
}