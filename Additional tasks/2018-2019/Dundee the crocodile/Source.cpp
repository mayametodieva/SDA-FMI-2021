#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
using namespace std;

int main() {

	priority_queue<string, vector<string>, greater<string>> res;

	map<string, int> unique;
	string word;
	string delimiter = " " ;
	getline(cin, word);

	size_t pos = 0;
	std::string token;
	while ((pos = word.find(delimiter)) != std::string::npos) {
		token = word.substr(0, pos);
		unique[token]++;
		word.erase(0, pos + delimiter.length());
	}

	unique[word]++;

	getline(cin, word);
	while ((pos = word.find(delimiter)) != std::string::npos) {
		token = word.substr(0, pos);
		unique[token]++;
		word.erase(0, pos + delimiter.length());
	}

	unique[word]++;

	for (auto it : unique)
	{
		if (it.second == 1)
		{
			res.push(it.first);
		}
	}

	while (!res.empty())
	{
		cout << res.top() << "\n";
		res.pop();
	}

    return 0;
}



/*#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> words;
	string line, currentword;

	while (getline(cin, line))
	{
		if (line == "\0")
			break;

		istringstream stream(line);

			while (stream >> currentword)
				words.push_back(currentword);
	}

	for (int i = 0; i < words.size(); i++)
	{
		cout << i << ": " << words[i] << "\n";
	}


}*/