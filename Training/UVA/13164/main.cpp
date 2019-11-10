#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll vertices;
  while (cin >> vertices) {

    vector<vector<pair<ll, ll>>> adj_list(vertices, vector<pair<ll, ll>>());
    vector<ll> ranks(vertices);
    ll manager = -1;
    for (ll i = 0; i < vertices; ++i) {
      ll m, r, t;
      cin >> m >> r >> t;
      ranks[i] = r;
      if (m == -1) {
        manager = i;
        continue;
      }
      adj_list[m - 1].push_back(make_pair(i, t));
    }

    vector<ll> times(vertices);

    function<void(ll, vector<ll>)> dfs;
    dfs = [&](ll i, vector<ll> path) {
      path.push_back(i);
      for (auto edge : adj_list[i]) {
        for (ll j = 0; j < (ll)path.size(); ++j) {
          if (ranks[edge.first] < ranks[path[j]]) {
            times[path[j]] += edge.second;
          }
        }
        dfs(edge.first, path);
      }
    };
    vector<ll> path;
    dfs(manager, path);
    for (ll i = 0; i < vertices; ++i) {
      cout << times[i] << "\n";
    }
  }
}
