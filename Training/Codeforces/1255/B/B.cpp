#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class disjoint_set {
    std::unique_ptr<size_t[]> parent, rank;

public:
    explicit disjoint_set(size_t n) : parent(new size_t[n]), rank(new size_t[n]) {
        for (size_t x = 0; x != n; ++x) {
            parent[x] = x;
            rank[x] = 0;
        }
    }
    size_t find_set(size_t x) {
        if (parent[x] != x)
            parent[x] = find_set(parent[x]);
        return parent[x];
    }

    bool union_set(size_t x, size_t y) {
        x = find_set(x);
        y = find_set(y);
        if (x == y)
            return false;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            ++rank[x];
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;

        vector<int> costs(n);
        for (int i = 0; i < n; ++i) {
            cin >> costs[i];
        }

        vector<vector<pair<ll, ll>>> list(n);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                list[i].push_back(make_pair(costs[i] + costs[j], j));
                list[j].push_back(make_pair(costs[i] + costs[j], i));
            }
        }

        disjoint_set ds(n);

        // print_list(adj_list);
        ll sum = 0;
        vector<pair<ll, pair<ll, ll>>> edges;
        set<pair<ll, ll>> used;
        vector<ll> used_edges(n);
        for (int i = 0; i < n; ++i) {
            sort(list[i].begin(), list[i].end());
            for (auto &edge : list[i]) {
                if (ds.find_set(edge.second) != ds.find_set(i)) {
                    sum += edge.first;
                    ds.union_set(edge.second, i);
                    edges.push_back(make_pair(edge.first, make_pair(i, edge.second)));
                    used.insert(make_pair(i, edge.second));
                    used.insert(make_pair(edge.second, i));
                    used_edges[i]++;
                    used_edges[edge.second]++;
                }
            }

            while (used_edges[i] != 2) {
                for (auto &edge : list[i]) {
                    if (used.find(make_pair(i, edge.second)) == used.end()) {
                        sum += edge.first;
                        ds.union_set(edge.second, i);
                        edges.push_back(make_pair(edge.first, make_pair(i, edge.second)));
                        used.insert(make_pair(i, edge.second));
                        used.insert(make_pair(edge.second, i));
                        used_edges[i]++;
                        used_edges[edge.second]++;
                    }

                    if (used_edges[i] == 2) {
                        break;
                    }
                }
            }
        }

        if (edges.size() > m) {
            cout << "-1\n";
            continue;
        }

        while (edges.size() < m) {
            edges.push_back(edges.front());
            sum += edges.front().first;
        }

        cout << sum << "\n";
        for (auto &edge : edges) {
            cout << edge.second.first + 1 << " " << edge.second.second + 1 << "\n";
        }
    }
}
