#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//ABCC1254asrv
//65 66 67 67 1 2 5 4 97 115 114 118

int convertToNumber(char a) {
	int number;
	if (int(a) >= int('0') && int(a)  <= int('9'))
	{
		number = int(a) - 47;
	}
	else if (int(a) >= int('a') && int(a) <= int('z'))
	{
		number = int(a) - 86;
	}
	else if (int(a) >= int('A') && int(a) <= int('Z'))
	{
		number = int(a) - 28;
	}
	return number;
}

int convertToSymbols(int a) {
	char symbol;
	if (a >= 1 && a <= 10)
	{
		symbol = int(a) + 47;
	}
	else if (a >= 11 && a <= 36)
	{
		symbol = int(a) + 86;
	}
	else if (a >= 37 && a <= 62)
	{
		symbol = int(a) + 28;
	}
	return symbol;
}

vector<int> stringToNumbers(string arr, int N) {
	vector<int> numbers;
	for (int i = 0; i < N; i++)
	{
		int number = convertToNumber(arr[i]);
		numbers.push_back(number);
	}
	return numbers;
}

string sortedString(string arr, int N) {
	vector<int> numbers = stringToNumbers(arr, N);

	sort(numbers.begin(), numbers.end());

	string readyString;

	for (int i = 0; i < numbers.size(); i++)
	{
		readyString += convertToSymbols(numbers[i]);
	}

	return readyString;

}

int main() {
	int N;
	cin >> N;

	string arr;

	cin >> arr;

	cout << sortedString(arr, N);

	return 0;
}
