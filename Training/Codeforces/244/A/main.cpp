#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  vector<ll> slices(n * k, -1);
  vector<vector<ll>> children(k);
  for (ll i = 0; i < k; ++i) {
    ll x;
    cin >> x;
    slices[x - 1] = i;
    children[i].push_back(x);
  }

  for (ll i = 0; i < k; ++i) {
    ll index = children[i][0] - 1;
    while (children[i].size() < n) {
      index = (index + 1) % (n * k);
      if (slices[index] != -1) {
        continue;
      }
      //   cout << "Adding slice " << index + 1 << " to childen " << i << endl;
      children[i].push_back(index + 1);
      slices[index] = i;
    }
  }

  for (ll i = 0; i < k; ++i) {
    for (ll j = 0; j < n; ++j) {
      cout << children[i][j];
      if (j + 1 < n) {
        cout << " ";
      } else {
        cout << "\n";
      }
    }
  }
}
