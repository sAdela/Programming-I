#include<iostream>
using namespace std;

void GoalsForGame(int Array[][12], int i, int j) {

	cout << "How many goals did the Player " << i+1 << " scored ? ";
	cin >> Array[i][j];


}

float PlayerGoalsForGame(int Array[][12], int Player) {
	float Average = 0;

	for (int i = 0; i < 12; i++) 

		if (Array[Player][i] != 0) {
			cout << "Goals for Gameday " << i + 1 << " : " << Array[Player][i] << endl;

			Average += Array[Player][i];
		}

	cout << "Player " << Player+1 << " average goals per game: ";

	return Average / 12;
}


float BestPlayer(int Array[][12]) {
	float Sum = 0, Max = 0, Index = 0;
	for (int i = 0; i < 11; i++) {
		Sum = 0;
		for (int j = 0; j < 12; j++) {

			Sum += Array[i][j];

		}
	
		if (Sum >= Max) {
			Index = i;
			Max = Sum;
		}

	}

	cout << "Best average is for player " << Index + 1 << ": " << Max/12;


	return Index;
}


void main() {

	int Array[11][12] = {0};
	int j, Player;
	cout << "For which game in season do you want to fill in the data about goals? ";

	do {
		cin >> j;
	} while (j < 1 || j > 12);

	j--;

	for (int i = 0; i < 11; i++) 
		GoalsForGame(Array, i, j);
	

	cout << "For which player do you want to see statistics? ";

	do {
		cin >> Player;
	} while (Player < 1 || Player > 11);

	Player--;

	cout << PlayerGoalsForGame(Array, Player) << endl;


	cout << BestPlayer(Array);



	system("Pause>0");
}