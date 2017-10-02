/*******************
* COMP11
* Homework 2
* Problem 2
* Eberechukwu Justin
*********************/

#include <iostream>
#include <string>

using namespace std;

//variable declarations
const string ALLOWED_LETTERS = "roygbv";
const string SECRET_CODE = "grob";

char user_answer[4];//stores the users answers 
char play_again;
bool allowed = false;
bool answer_used[4] = {false, false, false, false};//keeps track of which elements in the secret code have been used
int black_pegs, white_pegs;


bool is_allowed(char x);

int main()
{
	cout << "Welcome to THE MASTERMIND!\n";
	cout << "Enter your guesses\nr for red\no for orange\ny for yellow\n";
	cout << "g for green\nb for blue and\nv for violet\n\n";
	
	do
	{
		for (int i = 0; i < 4; ++i)
		{
			while (allowed == false)
			{
				cout << "Enter a guess: ";
				cin >> user_answer[i];
				allowed = is_allowed(user_answer[i]);
				if (allowed == false)
					cout << "Please enter a valid letter\n";
			}
			allowed = false;
		}


		for (int i = 0; i < 4; ++i)
		{	
			if(user_answer[i] == SECRET_CODE[i])
			{
				black_pegs++ ;
				answer_used[i] = true;//makes each used letter true so it wont be used again
			}
		}

		for (int i = 0; i < 4; ++i)//i represents the users answers
		{
			for (int j = 0; j < 4; ++j)//j represents the secret code, each i is checked with every j
			{
				if((user_answer[i] == SECRET_CODE[j]) && (answer_used[j]== false))//increases white_pegs only if answer_used is still false
				{
					white_pegs++;
					answer_used[j] = true;
				}
			}

		}
		if (black_pegs == 4)
		{
			cout << "You win! Your guess was right\n";
			return 0;
		}
		else
		{
			cout << "Result: " << black_pegs << " black pegs and " << white_pegs << " white pegs." ;
		}
		cout << "Do you want to play again y/n? ";
		do
		{
			cin >> play_again;
			if (!(play_again == 'y' || play_again == 'n'))
				cout << "Please enter y or n\n";
		}
		while (!(play_again == 'y' || play_again == 'n'));

		//resets the variables for the next iteration
		black_pegs = 0, white_pegs = 0;
		for (int i = 0; i < 4; ++i)
		{
			answer_used[i] = false;
		}
	}
	while (play_again == 'y'); 
	//all the code is enclosed in a do-while loop to continue the game if the user chooses to play again


	return 0;
}

//function to check if entered color is among the allowed colors
bool is_allowed(char x)
{
	int count = 0;
	for (string::size_type k = 0; k < ALLOWED_LETTERS.size(); ++k)
	{
		if (x == ALLOWED_LETTERS[k])
			count++;
	}
	if (count == 0) //count == 0 means no allowed letter matched the entered letter, thus false
		return false;
	else
		return true;

}