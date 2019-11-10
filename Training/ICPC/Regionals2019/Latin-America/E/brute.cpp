#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string cake;
  cin >> cake;
  ll n = (ll)cake.size();
  ll max_slices;
  cin >> max_slices;

  cake += cake.substr(0, max_slices);
  ll sum = 0;
  for (ll i = 1; i - 1 < max_slices; ++i) {
    for (ll j = 0; j < n; ++j) {
      string slice = cake.substr(j, i);
      sum += (ll)any_of(slice.begin(), slice.end(),
                        [](char x) { return x == 'E'; });
    }
  }
  cout << sum << endl;
}
