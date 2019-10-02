#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

/*
 * typedef vector<sizet> vect;
 * typedef pair<sizet,sizet> pares;
 */

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<bool> alphabet(26);
  sizet amount;
  string input;
  cin >> amount >> input;
  if (amount < alphabet.size()) {
    cout << "NO\n";
    return 0;
  }

  for (auto &chr : input) {
    alphabet[tolower(chr) - 'a'] = 1;
  }

  for (auto chr : alphabet) {
    if (!chr) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
}
