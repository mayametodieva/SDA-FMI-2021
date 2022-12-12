#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isThereSuchSymbolInTheWord(string word, char symbol) {
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == symbol)
		{
			return true;
		}
	}
	return false;
}

int countSymbols(string word, char symbol) {
	int counter = 0;
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == symbol)
		{
			counter++;
		}
	}
	return counter;
}

int numberOfSymbols(string word, int N, char symbol) {

	if (!isThereSuchSymbolInTheWord(word, symbol) || word.size() == 0)
	{
		return 0;
	}
	else {
		int numberOfNeededSymbolsInTheWord = countSymbols(word, symbol);

		int numberOfIterations = 0;
		int counter = 0;
		if (N > word.size())
		{
			numberOfIterations = N / word.size();
			counter = numberOfIterations * numberOfNeededSymbolsInTheWord;
			int leftNumbers = N % word.size();
			for (int i = 0; i < leftNumbers; i++) {
				if (word[i] == symbol)
				{
					counter++;
				}
			}
			return counter;
		}
		else
		{
			int leftNumbers = word.size() - N;
			int counter = 0;
			for (int i = 0; i < leftNumbers; i++) {
				if (word[i] == symbol)
				{
					counter++;
				}
			}
			return counter;
		}
	}
}

int main() {
	string word;

	cin >> word;

	int numberOfLetters;

	cin >> numberOfLetters;

	char symbol;

	cin >> symbol;

	cout << numberOfSymbols(word, numberOfLetters, symbol);

	return 0;
}