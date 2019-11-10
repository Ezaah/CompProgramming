#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x;
  cin >> n >> x;
  vector<ll> points(n);
  for (ll i = 0; i < n; ++i) {
    cin >> points[i];
  }

  sort(points.begin(), points.end());
  ll max_views = 0;
  for (ll i = 0; i < n; ++i) {
    ll views = 1;
    ll j = i;
    while (j + 1 < n) {
      if (points[j + 1] - points[j] <= x) {
        views++;
        j++;
      } else {
        break;
      }
    }

    max_views = max(views, max_views);
  }

  cout << max_views << "\n";
}
