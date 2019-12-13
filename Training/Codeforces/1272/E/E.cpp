#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> even, odd;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] % 2) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }

        int li = i - p[i];
        int lr = i + p[i];

        if (li > -1) {
            adj[li].push_back(i);
        }

        if (lr < n) {
            adj[lr].push_back(i);
        }
    }

    vector<int> ans(n, -1);
    function<void(vector<int>, vector<int>)> bfs;
    bfs = [&](vector<int> start, vector<int> end) {
        queue<int> que;
        vector<int> dist(n, 1e9);
        for (int v : start) {
            dist[v] = 0;
            que.push(v);
        }

        while (que.size()) {
            int v = que.front();
            que.pop();
            // cout << "Reached vertex " << v << endl;
            for (int u : adj[v]) {
                if (dist[u] == 1e9) {
                    // cout << "Setting dist of " << u << " from " << v << " as " << dist[v] + 1 << endl;
                    que.push(u);
                    dist[u] = dist[v] + 1;
                }
            }
        }

        for (int v : end) {
            if (dist[v] != 1e9) {
                ans[v] = dist[v];
            }
        }
    };

    bfs(even, odd);
    bfs(odd, even);

    for (int elem : ans) {
        cout << elem << " ";
    }
    cout << endl;

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
