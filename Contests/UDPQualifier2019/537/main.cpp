#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet tests;
	string input;
	getline(cin, input);
	tests = stoll(input);
	for (sizet i = 1; i < tests + 1; ++i)
	{
		vector<char> concepts(2);
		vector<char> prefixs(2);
		vector<char> units(2);
		vector<double> values(2);
		getline(cin, input);
		sizet pos = input.find_first_of('=');
		concepts[0] = input[pos - 1];
		string value_str = "";
		for (sizet k = pos + 1; k < input.size(); ++k)
		{
			if (isalpha(input[k]))
			{

				if (input[k] == 'm' || input[k] == 'k' || input[k] == 'M')
				{
					prefixs[0] = input[k];
				}
				else
				{
					units[0] = input[k];
					break;
				}
			}
			else
			{
				value_str += input[k];
			}
		}
		values[0] = stod(value_str);
		if (prefixs[0] == 'k')
		{
			values[0] *= 1e3;
		}
		else if (prefixs[0] == 'm')
		{
			values[0] *= 1e-3;
		}
		else if (prefixs[0] == 'M')
		{
			values[0] *= 1e6;
		}

		pos = input.find_last_of('=');
		concepts[1] = input[pos - 1];
		value_str = "";
		for (sizet k = pos + 1; k < input.size(); ++k)
		{
			if (isalpha(input[k]))
			{

				if (input[k] == 'm' || input[k] == 'k' || input[k] == 'M')
				{
					prefixs[1] = input[k];
				}
				else
				{
					units[1] = input[k];
					break;
				}
			}
			else
			{
				value_str += input[k];
			}
		}
		values[1] = stod(value_str);
		if (prefixs[1] == 'k')
		{
			values[1] *= 1e3;
		}
		else if (prefixs[1] == 'm')
		{
			values[1] *= 1e-3;
		}
		else if (prefixs[1] == 'M')
		{
			values[1] *= 1e6;
		}
		// cout << concepts[0] << " " << concepts[1] << endl;
		// cout << prefixs[0] << " " << prefixs[1] << endl;
		// cout << values[0] << " " << values[1] << endl;
		char o_concept;
		double o_value;
		char o_unit;
		if (concepts[0] == 'P')
		{
			if (concepts[1] == 'U')
			{
				o_concept = 'I';
				o_unit = 'A';
				o_value = values[0] / values[1];
			}
			else
			{
				o_concept = 'U';
				o_unit = 'V';
				o_value = values[0] / values[1];
			}
		}
		else if (concepts[0] == 'U')
		{
			if (concepts[1] == 'P')
			{
				o_concept = 'I';
				o_unit = 'A';
				o_value = values[1] / values[0];
			}
			else
			{
				o_concept = 'P';
				o_unit = 'W';
				o_value = values[0] * values[1];
			}
		}
		else
		{
			if (concepts[1] == 'P')
			{
				o_concept = 'U';
				o_unit = 'V';
				o_value = values[1] / values[0];
			}
			else
			{
				o_concept = 'P';
				o_unit = 'W';
				o_value = values[0] * values[1];
			}
		}

		printf("Problem #%lli\n%c=%.2f%c\n\n", i, o_concept, o_value, o_unit);
	}
}
