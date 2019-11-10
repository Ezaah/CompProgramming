#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;
  vector<ll> members(n);
  for (ll i = 0; i < n; ++i) {
    cin >> members[i];
    members[i] += k;
  }

  ll candidates =
      count_if(members.begin(), members.end(), [](ll a) { return a < 6; });
  cout << candidates / 3 << "\n";
}
