#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Debug prints copied from Tourist on codeforces
// (Not all of them, only the ones I use the most)
template <typename T, typename Y>
string to_string(pair<T, Y> a);

string to_string(const string &a) {
    return "\"" + a + "\"";
}

string to_string(const char *a) {
    return to_string((string)a);
}
string to_string(bool a) {
    return a ? "true" : "false";
}
string to_string(vector<bool> v) {
    string res = "{";
    for (size_t i = 0; i < static_cast<size_t>(v.size()); i++) {
        if (i != 0) {
            res += ", ";
        }
        res += to_string(v[i]);
    }
    return res + "}";
}
string to_string(char a) {
    return "'" + string(1, a) + "'";
}
template <typename T>
string to_string(stack<T> v) {
    string res = "{";
    stack<T> aux = v;
    while (!aux.empty()) {
        if (res != "{") {
            res += ", ";
        }
        res += to_string(aux.top());
        aux.pop();
    }
    return res + "}";
}
template <typename T>
string to_string(T v) {
    string res = "{";
    for (const auto &x : v) {
        if (res != "{") {
            res += ", ";
        }
        res += to_string(x);
    }
    return res + "}";
}
template <typename T, typename Y>
string to_string(pair<T, Y> a) {
    return "{" + to_string(a.first) + ", " + to_string(a.second) + "}";
}

void debug_out() {
    cerr << endl;
}

template <typename Front, typename... Rest>
void debug_out(Front F, Rest... R) {
    cerr << " " << to_string(F);
    debug_out(R...);
}
#ifdef LOCAL_DEFINE
#define debug(...) cerr << " [" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 13
#endif

// To debug custom types, you need to create his own 'to_string()' function
// Ex:
// struct foo {
//     ...
// };
// string to_string(foo a){
//     return "{" + to_string(a.a) + ... + to_string(a.z) + "}";
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;

    int tests;
    cin >> tests;
    while (tests--) {
        string pass;
        cin >> pass;
        ll n = pass.size();
        vector<set<ll>> adj(26);

        for (ll i = 0; i + 1 < n; ++i) {
            ll u = pass[i] - 'a';
            ll v = pass[i + 1] - 'a';

            adj[u].insert(v);
            adj[v].insert(u);
        }

        debug(adj);
        bool impossible = 0;
        for (ll i = 0; i < 26; ++i) {
            if (adj[i].size() > 2) {
                impossible = 1;
                break;
            }
        }

        vector<bool> visited(26);
        function<void(ll, ll)> dfs;
        dfs = [&](ll u, ll par) {
            visited[u] = 1;
            for (auto &v : adj[u]) {

                if (visited[v] && v != par) {
                    impossible = 1;
                    return;
                }

                if (v != par) {
                    dfs(v, u);
                }
            }
        };

        for (ll i = 0; i < 26; ++i) {
            if (!visited[i]) {
                dfs(i, i);
            }
        }

        if (impossible) {
            cout << "NO\n";
            continue;
        }
        visited = vector<bool>(26);
        stack<ll> path;
        function<void(ll, ll)> dfs_path;
        dfs_path = [&](ll u, ll par) {
            visited[u] = 1;
            path.push(u);

            for (auto &v : adj[u]) {

                if (v != par) {
                    dfs_path(v, u);
                }
            }
        };
        for (ll i = 0; i < 26; ++i) {
            if (adj[i].size() == 1) {
                dfs_path(i, i);
                break;
            }
        }
        for (ll i = 0; i < 26; ++i) {
            if (!visited[i]) {
                dfs_path(i, i);
            }
        }

        cout << "YES\n";
        while (!path.empty()) {
            ll u = path.top();
            path.pop();
            char ans = 'a' + u;
            cout << ans;
        }
        cout << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
