#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;

  ll drinks = (k * l) / nl;
  ll limes = c * d;
  ll salt = p / np;
  cout << min({drinks, limes, salt}) / n << "\n";
}
