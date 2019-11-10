#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll tests;
  cin >> tests;
  while (tests--) {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    ll diffs = 0;
    vector<ll> combinations;
    for (ll i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        diffs++;
        combinations.push_back(i);
        // cout << i << ": " << a[i] << " " << b[i] << " " << diffs << endl;
      }
    }

    if (diffs != 2) {
      cout << "No\n";
      continue;
    }

    bool possible = 0;
    for (ll i = 0; i < diffs; ++i) {
      for (ll j = 0; j < diffs; ++j) {
        if (i == j) {
          continue;
        }
        swap(a[combinations[i]], b[combinations[j]]);
        if (a == b) {
          possible = 1;
          break;
        }
        swap(a[combinations[i]], b[combinations[j]]);
      }
      if (possible) {
        break;
      }
    }
    if (possible) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
