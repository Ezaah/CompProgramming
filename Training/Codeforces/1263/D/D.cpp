#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool equal_str(string &a, string &b) {

    set<char> letters;
    for (char chr : a) {
        letters.insert(chr);
    }

    for (char chr : b) {
        if (letters.find(chr) != letters.end()) {

            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<string> pass(n);
    vector<ll> parent(n);
    vector<ll> rank(n);

    for (ll i = 0; i < n; ++i) {
        cin >> pass[i];
        parent[i] = i;
        rank[i] = 0;
    }

    function<ll(ll)> find_set;
    find_set = [&](ll x) {
        if (parent[x] != x) {
            parent[x] = find_set(parent[x]);
        }

        return parent[x];
    };

    function<bool(ll, ll)> union_set;
    union_set = [&](ll x, ll y) {
        x = find_set(x);
        y = find_set(y);

        if (x == y) {
            return false;
        }

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            ++rank[x];
        }
        return true;
    };

    sort(pass.rbegin(), pass.rend());
    for (ll i = 0; i + 1 < n; ++i) {

        if (find_set(i) != find_set(i + 1) && equal_str(pass[i], pass[i + 1])) {
            union_set(i, i + 1);
        }
    }

    vector<ll> uniq(n);
    auto last = unique_copy(parent.begin(), parent.end(), uniq.begin());
    uniq.erase(last, uniq.end());
    cout << uniq.size() << "\n";
}
