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
ll MOD = 998244353;

ll mod_inverse(ll a, ll m = MOD) {
    ll r = a;
    ll old_r = m;
    ll t = 1;
    ll old_t = 0;

    while (r) {
        ll quotient = old_r / r;
        ll tmp;
        tmp = r, r = old_r - quotient * r, old_r = tmp;
        tmp = t, t = old_t - quotient * t, old_t = tmp;
    }

    if (old_r < 0) {
        old_r = -old_r, old_t = -old_t;
    }

    if (old_r != 1) {
        return m;
    }

    return old_t < 0 ? old_t + m : old_t;
}

ll mod_add(ll a, ll b, ll m = MOD) {
    if (a < m - b) {
        return a + b;
    }
    return a - (m - b);
}

ll mod_mul(ll a, ll b, ll m = MOD) {
    ll res = 0;
    while (b) {
        if (b % 2 == 1) {
            res = mod_add(a, res, m);
        }
        a = mod_add(a, a, m);
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;

    ll n;
    cin >> n;
    vector<vector<ll>> items(n);
    map<ll, ll> freq;
    vector<ll> sizes(n);
    for (ll i = 0; i < n; ++i) {
        cin >> sizes[i];
        items[i].resize(sizes[i]);

        for (ll j = 0; j < sizes[i]; ++j) {
            cin >> items[i][j];
            if (freq.count(items[i][j])) {
                freq[items[i][j]]++;
            } else {
                freq.insert(make_pair(items[i][j], 1));
            }
        }
    }

    ll x = mod_mul(1, mod_inverse(n));
    ll sum = 0;

    for (ll i = 0; i < n; ++i) {

        ll k = mod_mul(1, mod_inverse(sizes[i]));
        ll ksum = 0;
        for (ll j = 0; j < sizes[i]; ++j) {

            ll zj = mod_mul(freq[items[i][j]], mod_inverse(n));
            ksum = mod_add(ksum, zj);
        }

        sum = mod_add(sum, mod_mul(k, ksum));
    }

    x = mod_mul(x, sum);
    cout << x << "\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
