#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, t;
  cin >> n >> t;
  string queue;
  cin >> queue;

  for (ll i = 0; i < t; ++i) {
    for (ll j = 0; j + 1 < n; ++j) {
      if (queue[j] == 'B' && queue[j + 1] == 'G') {
        swap(queue[j], queue[j + 1]);
        j++;
      }
    }
  }

  cout << queue << "\n";
}
