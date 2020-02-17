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

    ll n, m;
    cin >> n >> m;
    vector<ll> pos(n);
    map<ll, pair<ll, ll>> friends;
    map<ll, ll> actual_pos;
    for (ll i = 0; i < n; ++i) {
        pos[i] = i + 1;
        actual_pos.insert(make_pair(i + 1, i));
        friends.insert(make_pair(i + 1, make_pair(i + 1, i + 1)));
    }

    for (ll i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        for (ll j = actual_pos[x] - 1; j >= 0; --j) {
            swap(pos[j], pos[j + 1]);
        }

        debug(actual_pos);
        for (ll j = 0; j < n; ++j) {
            actual_pos[pos[j]] = j;
            friends[pos[j]].first = min(friends[pos[j]].first, j + 1);
            friends[pos[j]].second = max(friends[pos[j]].second, j + 1);
        }
        debug(friends, pos);
    }

    for (ll i = 1; i <= n; ++i) {
        cout << friends[i].first << " " << friends[i].second << "\n";
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
