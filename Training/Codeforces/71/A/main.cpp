#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<string> words(n);
  for (ll i = 0; i < n; ++i) {
    cin >> words[i];
  }

  for (string word : words) {
    if (word.size() > 10) {
      word = word.front() + to_string(word.size() - 2) + word.back();
    }

    cout << word << "\n";
  }
}
