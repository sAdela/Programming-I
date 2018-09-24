/*

Several monkeys were collecting bananas. When they finished collecting, they tried to put bananas in 11 same groups,
but it turned out that there's 7 bananas left that was impossible to put so that groups were same. 
Likewise, when they tried to put bananas in 24 same groups, there was 3 bananas that couldn't be placed.
But they managed to put bananas in 25 same groups. 
Determine what is the smallest number of bananas for which such a scenario is possible.

*/

#include<iostream>
using namespace std;

void main() {
	
	int numberOfBananas = 0;

	for (int i = 1; i < 1000; i++) {

		numberOfBananas = i * 11 + 7;

		if (numberOfBananas % 24 == 3 && numberOfBananas % 25 == 0) {

			cout << "Number of bananas: " << numberOfBananas << endl;
			break;

		}
		
	}

	system("pause>0");
}