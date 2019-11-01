#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

sizet to_decimal(vector<sizet> &trinary)
{
	sizet power = 1;
	sizet sum = 0;
	for (sizet i = (sizet)trinary.size() - 1; i > -1; --i, power *= 3)
	{
		sum += power * trinary[i];
	}
	return sum;
}

void print_trinary(vector<sizet> &trinary)
{
	printf("Trinary: ");
	for (auto x : trinary)
	{
		printf("%lld ", x);
	}
	printf("\n");
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet queries;
	scanf("%lld", &queries);
	double log3 = log10(3);
	vector<sizet> powers;
	while (queries--)
	{
		sizet n;
		scanf("%lld", &n);

		sizet max_exponent = ceil(log10(n) / log3);
		vector<sizet> trinary(max_exponent + 1);
		sizet pos = max_exponent;
		while (n > 0)
		{

			trinary[pos--] = n % 3;
			n /= 3;
		}

		if (count(trinary.begin(), trinary.end(), 2) == 0)
		{
			printf("%lld\n", to_decimal(trinary));
			continue;
		}
		// print_trinary(trinary);
		while (count(trinary.begin(), trinary.end(), 2) > 0)
		{

			for (sizet i = 0; i < max_exponent + 1; i++)
			{
				if (trinary[i] == 2)
				{
					trinary[i] = 0;
					trinary[i - 1]++;
					for (i++; i < max_exponent + 1; ++i)
					{
						trinary[i] = 0;
					}
				}
				// print_trinary(trinary);
			}
			// sizet carry = 1;
			// for (sizet i = max_exponent; i > -1; --i)
			// {

			// 	trinary[i] += carry;
			// 	carry = 0;
			// 	if (trinary[i] == 3)
			// 	{
			// 		trinary[i] = 0;
			// 		carry = 1;
			// 	}
			// }
			// print_trinary(trinary);
		}
		// print_trinary(trinary);

		printf("%lld\n", to_decimal(trinary));
	}
}
