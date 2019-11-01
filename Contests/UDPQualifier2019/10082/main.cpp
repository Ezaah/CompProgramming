#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<char, char> keyboard = {{'1', '`'}, {'2', '1'}, {'3', '2'}, {'4', '3'}, {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}, {'0', '9'}, {'-', '0'}, {'=', '-'}, {'\b', '='}, {'W', 'Q'}, {'E', 'W'}, {'R', 'E'}, {'T', 'R'}, {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'}, {'O', 'I'}, {'P', 'O'}, {'[', 'P'}, {']', '['}, {'\\', ']'}, {'S', 'A'}, {'D', 'S'}, {'F', 'D'}, {'G', 'F'}, {'H', 'G'}, {'J', 'H'}, {'K', 'J'}, {'L', 'K'}, {';', 'L'}, {'\'', ';'}, {'\n', '\''}, {'X', 'Z'}, {'C', 'X'}, {'V', 'C'}, {'B', 'V'}, {'N', 'B'}, {'M', 'N'}, {',', 'M'}, {'.', ','}, {'/', '.'}};

	string input;
	while (getline(cin, input))
	{
		string output = "";
		for (auto &chr : input)
		{
			if (keyboard.find(chr) != keyboard.end())
			{
				output += keyboard[chr];
			}
			else
			{
				output += chr;
			}
		}
		cout << output << "\n";
	}
}
