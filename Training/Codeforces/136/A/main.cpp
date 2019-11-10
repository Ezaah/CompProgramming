#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> received(n);
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    received[x - 1] = i + 1;
  }

  for (ll i = 0; i < n; ++i) {
    cout << received[i];
    if (i + 1 < n) {
      cout << " ";
    } else {
      cout << "\n";
    }
  }
}
