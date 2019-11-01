#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string word;
	cin >> word;
	string output = "";
	if (word.back() == 'a' || word.back() == 'o')
	{
		output = word.substr(0, word.size() - 1) + "ic" + word.back();
	}

	cout << output << "\n";
}
