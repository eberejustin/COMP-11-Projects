/********************
* COMP11
* Homework 1
* Problem 2
* Eberechukwu Justin
*********************/

#include <iostream>
#include <string>
using namespace std;

//variable definitions
int score = 0; 
string name;
char answer;

int main()
{
	cout << "What is your name child? ";
	cin >> name;

	cout << "\nWelcome to the labyrinth! "<< name << endl;
	cout <<"\nPlease answer questions with Y or N for yes or no\n\n";

	//the game begins
	cout << "Toby is crying his head off! \n\nDo you wish the Goblin King to take him away right now?\n";
	cin >> answer;

	if(answer == 'Y' || answer == 'y')
	{
		cout << "Ok, he did. You have 13 hours to solve the labyrinth\n\n";
		score++;

		cout << "Do you want to follow the talking worm?\n";
		cin >> answer;
		if(answer == 'Y' || answer == 'y')
		{
			cout << "With the worm's help, you find Hoggle then Ludo.\n\n";
			score +=2;

			cout << "Do you want to confront The Goblin King alone?\n";
			cin >> answer;
			if(answer == 'Y' || answer == 'y')
			{
				cout << "Good choice. He has no power over you.\n";
				score +=3;
			}
			else
				cout << "\nYou should have, he has no power over you!\n";
		}
		else
			cout << "\nYou should have followed him!\n";
	}


	cout << "\nLabyrinth over, You earned " << score <<" points.\n";
	if(score == 0)
		cout << "You will have to take care of baby Toby forever, Coward!\n";

	if(1<= score && score <= 5)
		cout << "You're Ok " << name << ". You will stay in the labyrinth with David Bowie\n";

	if(score == 6)
		cout << "That was perfect! Well done " << name << ".You get to go home and Ludo will be your best bud!";

	return 0;
}