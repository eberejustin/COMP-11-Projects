/*******************
* COMP11
* Homework 2
* Problem 2
* Eberechukwu Justin
*********************/

#include <iostream>
#include <string>
#include <set>

using namespace std;
int num_of_words;
string one_word; //stores each word input from the user
set<string> words_to_sort; //stores and sorts all the entered words
bool is_allowed(string x);

int main()
{
	

	cout <<"This program can sort any words in alphabetical order\n";
	cout <<"How many numbers do you want to sort?(must be greater than one) ";
	do
	{
		cin >> num_of_words;
		if (num_of_words <= 1)
			cout << "Please enter a number greater than 1: ";
	}
	while (num_of_words <= 1);

	cout << "Enter a word: ";
	cin >> one_word;
	words_to_sort.insert(one_word);
	for (int i = 0; i < (num_of_words - 1); ++i)
	{
		cout << "enter another word: ";
		cin >> one_word;
		//check if entered word is already in the set
		while(!is_allowed(one_word))
		{
			cout << "You already entered that, please enter another word: ";
			cin >> one_word; 		
		}
		//after user enters an allowed word, adds it to the set
		words_to_sort.insert(one_word);
	}

	cout << "Here are your words sorted alphabetically\n";
		 
	//sets are sorted by default so printing out the elements of the set gives the words in a lphabetical order
	for(set<string>::iterator j = words_to_sort.begin(); j != words_to_sort.end(); ++j)
	{
		cout << *j << endl;
	}
	return 0;	
}

//function to check if a word has been entered before, loops through the set and returns true if entered word is not same as any word on the set
bool is_allowed(string x)
{
	int count = 0;
	for (set<string>::iterator j = words_to_sort.begin(); j != words_to_sort.end(); ++j)
	{
		if (x == *j)
			count++;
	}
	if (count == 0)
		return true;
	else
		return false;

}
