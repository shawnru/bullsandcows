// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "ctime"
#include "string"
#include "unordered_map"
using namespace std;

void startProgram();
void wordAssignment();
auto getWordLength(string winningWord);

int main()
{
	startProgram();
	wordAssignment();

	return 0;
}

void startProgram()
{
	cout << "Hello welcome to Bulls&Cows" << endl;
	cout << "Rules:" << endl;
	cout << "You are going to be given a random isogram (a word that has no repeating letters) that you have to guess" << endl;
	cout << "The only hint you will be given before playing is how many letters there are." << endl;
	cout << "After your first guess you will be given a number of Bulls and Cows. The Bulls means you have the correct letter in the correct space while a Cow means you have the correct letter in an incorrect area." << endl;
	cout << "The number of tries you get depends on the length of the word you're given" << endl;
}


auto getWordLength(string winningWord)
{
	string wordGuess;
	int numberOfTries;
	int numberOfGuesses;
	int lengthofWinningWordTries = winningWord.length();
	if (lengthofWinningWordTries == 4)
	{
		numberOfTries = 10;
		numberOfGuesses = 10;
	}

	else if (lengthofWinningWordTries == 5)
	{
		numberOfTries = 12;
		numberOfGuesses = 12;
	}

	for (int i = 0; i < numberOfTries; i++)
	{
		int numberOfBulls = 0;
		int numberOfCows = 0;
		cout << "Can you guess the " << winningWord.length() << " letter word I'm thinking of?" << endl;
		cout << "You have " << numberOfGuesses << " left" << endl;
		cin >> wordGuess;
		cout << endl;

		if ((wordGuess.length() > winningWord.length()) || (wordGuess.length() < winningWord.length()))
		{
			cout << "Please type a word that is " << winningWord.length() << " letters in length" << endl;
			--i;
		}
		if (wordGuess[0] == winningWord[0])
		{
			++numberOfBulls;
		}
		if (wordGuess[0] == winningWord[1] || wordGuess[0] == winningWord[2] || wordGuess[0] == winningWord[3] || wordGuess[0] == winningWord[4])
		{
			++numberOfCows;
		}
		if (wordGuess[1] == winningWord[1])
		{
			++numberOfBulls;
		}
		if (wordGuess[1] == winningWord[0] || wordGuess[1] == winningWord[2] || wordGuess[1] == winningWord[3] || wordGuess[1] == winningWord[4])
		{
			++numberOfCows;
		}
		if (wordGuess[2] == winningWord[2])
		{
			++numberOfBulls;
		}
		if (wordGuess[2] == winningWord[0] || wordGuess[2] == winningWord[1] || wordGuess[2] == winningWord[3] || wordGuess[2] == winningWord[4])
		{
			++numberOfCows;
		}
		if (wordGuess[3] == winningWord[3])
		{
			++numberOfBulls;
		}
		if (wordGuess[3] == winningWord[0] || wordGuess[3] == winningWord[1] || wordGuess[3] == winningWord[2] || wordGuess[3] == winningWord[4])
		{
			++numberOfCows;
		}
		if ((wordGuess[4] == winningWord[4]) && (wordGuess.length() > 4))
		{
			++numberOfBulls;
		}
		if (wordGuess[4] == winningWord[0] || wordGuess[4] == winningWord[2] || wordGuess[4] == winningWord[3] || wordGuess[4] == winningWord[1])
		{
			++numberOfCows;
		}
		if (wordGuess == winningWord)
		{
			char answer = 'a';
			cout << "You win!" << endl;
			cout << "Would you like to try again?" << endl;
			cout << "Type 'y' to play again or 'n' to close program:";
			cin >> answer;
			if (answer == 'y')
				wordAssignment();
			else if(answer == 'n')
				return 0;
			else
				cout << "Please type y or n";
		}
		else
		{
			cout << "Bulls: " << numberOfBulls << " Cows: " << numberOfCows << endl;
			--numberOfGuesses;
		}
		if (numberOfGuesses == 0)
		{
			char answer = 'a';
			cout << "Sry squadfam, you lose" << endl;
			cout << "Would you like to try again?" << endl;
			cout << "Type 'y' to play again or 'n' to close program:";
			cin >> answer;
			if (answer == 'y')
				wordAssignment();
			else if (answer == 'n')
				return 0;
			else
				cout << "Please type y or n";
		}
	}

}

void wordAssignment()
{
	srand(time(0));
	int newWordNumber = rand() % 11 + 1;
	unordered_map<int, string> isogramList;
	unordered_map<int, string>::iterator it;

	isogramList.insert(make_pair(1, "myth"));
	isogramList.insert(make_pair(2, "duck"));
	isogramList.insert(make_pair(3, "verb"));
	isogramList.insert(make_pair(4, "gasp"));
	isogramList.insert(make_pair(5, "jinx"));
	isogramList.insert(make_pair(6, "wolf"));
	isogramList.insert(make_pair(7, "black"));
	isogramList.insert(make_pair(8, "fight"));
	isogramList.insert(make_pair(9, "jumpy"));
	isogramList.insert(make_pair(10, "drown"));
	isogramList.insert(make_pair(11, "crash"));

	string winningWord = isogramList[newWordNumber];
	getWordLength(winningWord);
}

