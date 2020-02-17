#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool intersect(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first > b.second || a.second < a.first) {
        return false;
    }

    if (a.first < b.first && b.second < a.second) {
        return false;
    }

    if (b.first < a.first && a.second < b.second) {
        return false;
    }

    return true;
}

ostream &operator<<(ostream &o, const pair<ll, ll> &n) {
    return o << "[" << n.first << "," << n.second << "]";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    ll n;
    cin >> n;

    vector<pair<ll, ll>> seg(n);
    map<pair<ll, ll>, ll> ids;
    for (ll i = 0; i < n; ++i) {
        cin >> seg[i].first >> seg[i].second;
        ids.insert(make_pair(seg[i], i));
    }

    vector<vector<ll>> adj(n);
    sort(seg.begin(), seg.end());
    for (auto i = seg.begin(); i != seg.end(); ++i) {
        auto it = lower_bound(seg.begin(), seg.end(), make_pair(i->second, 0LL));
        for (auto j = i + 1; j != it; ++j) {

            if (intersect(*i, *j)) {
                // cout << "Union of " << seg[i] << " " << seg[j] << endl;
                // if (!dset.union_set(i, i + 1)) {
                //
                //     cycle = 1;
                //     break;
                // }
                adj[ids[*i]].push_back(ids[*j]);
                adj[ids[*j]].push_back(ids[*i]);
            }
        }
    }
    bool cycle = 0;
    vector<bool> visited(n);
    function<void(ll, ll)> dfs;
    dfs = [&](ll v, ll p) {
        visited[v] = 1;

        for (ll u : adj[v]) {
            if (u == p) {
                continue;
            }

            if (visited[u]) {
                cycle = 1;
                return;
            }

            dfs(u, v);
        }
    };

    dfs(0, -1);

    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            cycle = 1;
            break;
        }
    }
    if (cycle) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
