#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

void print_pile(vector<sizet> a)
{
	for (auto elem : a)
	{
		cout << elem << " ";
	}
	cout << endl;
}
bool check_combination(sizet a, sizet b, sizet c)
{
	if (a + b + c == 10)
	{
		return true;
	}
	if (a + b + c == 20)
	{
		return true;
	}

	if (a + b + c == 30)
	{
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet maxCards = 52;
	queue<sizet> deck;
	sizet turn = 0;
	sizet startCard;
	while (cin >> startCard)
	{
		if (startCard == 0)
		{
			break;
		}
		deck.push(startCard);
		for (sizet i = 1; i < maxCards; ++i)
		{
			cin >> startCard;
			deck.push(startCard);
		}
		queue<vector<sizet>> piles;
		for (sizet i = 0; i < 7; ++i)
		{
			piles.push({deck.front()});
			deck.pop();
			turn++;
		}

		bool win = 0;
		bool lose = 0;
		bool draw = 0;
		vector<sizet> lastPile;
		while (1)
		{
			cout << "\t" << piles.size() << " # Pilas" << endl;
			if (piles.size() == 0)
			{
				bool win = 1;
				break;
			}
			auto pile = piles.front();
			piles.pop();
			// cout << pile.size() << " # Cartas en la pila" << endl;

			// if (pile == lastPile)
			// {
			// 	draw = 1;
			// 	break;
			// }
			// cout << deck.size() << " # Cartas restantes" << endl;
			if (deck.size() == 0)
			{
				lose = 1;
			}
			cout << "\t Before Draw (" << deck.size() << ")\n";
			print_pile(pile);
			sizet card = deck.front();
			deck.pop();
			pile.insert(pile.begin(), card);

			cout << "\t After Draw(" << deck.size() << ")\n";
			print_pile(pile);

			turn++;
			while (pile.size() > 2)
			{
				sizet lastPos = pile.size() - 1;
				if (check_combination(pile[0], pile[1], pile[lastPos]))
				{
					cout << "#1 Number matched with " << pile[0] << " " << pile[1] << " " << pile[lastPos] << endl;
					deck.push(pile[0]);
					deck.push(pile[1]);
					deck.push(pile[lastPos]);

					pile.erase(pile.begin());

					pile.erase(pile.begin());

					pile.pop_back();
				}
				else if (check_combination(pile[0], pile[lastPos - 1], pile[lastPos]))
				{
					cout << "#2 Number matched with " << pile[0] << " " << pile[lastPos - 1] << " " << pile[lastPos] << endl;
					deck.push(pile[0]);
					deck.push(pile[lastPos - 1]);
					deck.push(pile[lastPos]);
					pile.pop_back();
					pile.pop_back();
					pile.erase(pile.begin());
				}
				else if (check_combination(pile[lastPos - 2], pile[lastPos - 1], pile[lastPos]))
				{
					cout << "#3 Number matched with " << pile[lastPos - 2] << " " << pile[lastPos - 1] << " " << pile[lastPos] << endl;
					deck.push(pile[lastPos - 2]);
					deck.push(pile[lastPos - 1]);
					deck.push(pile[lastPos]);
					pile.pop_back();
					pile.pop_back();
					pile.pop_back();
				}
				else
				{
					break;
				}
			}
			if (pile.size() > 0)
			{
				// lastPile = pile;
				piles.push(pile);
			}
		}
		if (win)
		{
			cout << "Win : ";
		}
		if (lose)
		{
			cout << "Loss: ";
		}
		if (draw)
		{
			cout << "Draw: ";
		}

		cout << turn << "\n";
	}
}
