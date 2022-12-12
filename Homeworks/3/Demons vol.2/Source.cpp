#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Demons {
public:
	Demons() : defense(0), attack(0) {}
	Demons(long long defense, long long attack) : defense(defense), attack(attack) {}

	long long getDefense() const;
	long long getAttack() const;
private:
	long long defense;
	long long attack;
};

long long Demons::getAttack() const
{
	return this->attack;
}

long long Demons::getDefense() const
{
	return this->defense;
}

bool operator<(const Demons& first, const Demons& second) {
	return first.getDefense() < second.getDefense() && first.getAttack() < second.getAttack();
}

bool operator==(const Demons& first, const Demons& second) {
	return first.getDefense() == second.getDefense() && first.getAttack() == second.getAttack();
}

long long BinarySearch(vector<Demons>& arr, long long left, long long right, Demons value) {

	while (right - left > 1)
	{
		long long mid = left + (right - left) / 2;

		if (arr[mid] < value)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return right;
}


long long biggestNumberOfKilledDemons(const vector<Demons>& demons)
{
	if (demons.size() == 0) {
		return 0;
	}

	vector<Demons> sub(demons.size(), Demons(0,0));

	long long counter = 1;

	sub[0] = demons[0];

	for (long long i = 0; i < demons.size(); i++)
	{
		if (demons[i] < sub[0])
		{
			sub[0] = demons[i];
		}
		else if (sub[counter - 1] < demons[i]) {
			sub[counter] = demons[i];
			counter++;
		}
		else
		{
			long long idx = BinarySearch(sub, -1, counter - 1, demons[i]);
			sub[idx] = demons[i];
		}	
	}

	return counter;
}


int main() {
	long long N;

	cin >> N;

	vector<Demons> demons;

	for (long long i = 0; i < N; i++)
	{
		long long first, second;

		cin >> first >> second;

		Demons a(first, second);
		demons.push_back(a);
	}

	sort(demons.begin(), demons.end(), [](const Demons& par1, const Demons& par2) {
		if (par1.getDefense() == par2.getDefense())
		{
			return par1.getAttack() < par2.getAttack();
		}
		return par1.getDefense() < par2.getDefense();
		});

	cout << biggestNumberOfKilledDemons(demons);
	cout << endl;

	return 0;
}
