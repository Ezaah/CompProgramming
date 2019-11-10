#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> adj(n, vector<ll>(n));
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    cin >> u >> v;
    adj[u - 1][v - 1] = 1;
    adj[v - 1][u - 1] = 1;
  }

  vector<ll> dist(n, 1e9);
  vector<bool> visited(n);
  deque<ll> dq;
  dq.push_front(0);
  dist[0] = 0;
  while (!dq.empty()) {
    ll v = dq.front();
    dq.pop_front();
    for (ll i = 0; i < n; ++i) {
      if (i == v) {
        continue;
      }
      cout << v << " -> " << i << " (" << dist[v] << " + " << adj[v][i] << " < "
           << dist[i] << " ) [" << dq.size() << "]" << endl;
      if (dist[v] + adj[v][i] < dist[i]) {
        dist[i] = dist[v] + adj[v][i];
        if (adj[v][i] == 1) {
          dq.push_back(i);
        } else {
          dq.push_front(i);
        }
      }
    }
  }
  auto maximum = max_element(dist.begin(), dist.end());
  cout << *maximum << "\n";
}
