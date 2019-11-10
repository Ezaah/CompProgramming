#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string name, residence, pile;
  cin >> name >> residence >> pile;

  unordered_map<char, ll> freq;
  for (char letter : name) {
    if (freq.find(letter) == freq.end()) {
      freq[letter] = 1;
    } else {
      freq[letter]++;
    }
  }

  for (char letter : residence) {
    if (freq.find(letter) == freq.end()) {
      freq[letter] = 1;
    } else {
      freq[letter]++;
    }
  }

  bool possible = 1;
  for (char letter : pile) {
    if (freq.find(letter) == freq.end()) {
      possible = 0;
      break;
    }

    freq[letter]--;
  }

  for (auto elem : freq) {
    if (elem.second != 0) {
      possible = 0;
      break;
    }
  }

  possible ? cout << "YES\n" : cout << "NO\n";
}
