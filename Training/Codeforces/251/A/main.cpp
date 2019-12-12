#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed;

  ll n, d;
  cin >> n >> d;
  vector<ll> p(n);
  for (ll i = 0; i < n; ++i) {
    cin >> p[i];
  }

  ll cnt = 0;
  for (ll i = 0; i < n; ++i) {
    auto upper = upper_bound(p.begin() + i, p.end(), p[i] + d);
    ll dis = distance(p.begin() + i + 1, upper);
    if (dis < 2) {
      continue;
    }
    // cout << dis << " { " << p[i] << " "<<*upper << " } "  << dis*(dis-1)/2<<
    // endl;
    cnt += dis * (dis - 1) / 2;
  }
  cout << cnt << "\n";
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
