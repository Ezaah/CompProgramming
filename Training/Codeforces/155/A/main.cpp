#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> points(n);
  for (ll i = 0; i < n; ++i) {
    cin >> points[i];
  }
  ll amazing = 0;
  for (ll i = 1; i < n; ++i) {
    bool up = 1;
    bool down = 1;
    for (ll j = 0; j < i; ++j) {
      if (points[i] <= points[j]) {
        up = 0;
      }

      if (points[i] >= points[j]) {
        down = 0;
      }
    }

    if (up || down) {
      amazing++;
    }
  }

  cout << amazing << "\n";
}
