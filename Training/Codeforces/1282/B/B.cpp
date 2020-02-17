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

    int tests;
    cin >> tests;
    while (tests--) {
        ll n, k, p;
        cin >> n >> p >> k;
        vector<ll> items(n);
        for (ll i = 0; i < n; ++i) {
            cin >> items[i];
        }

        sort(items.rbegin(), items.rend());
        vector<ll> ans;
        multimap<ll, vector<ll>, greater<ll>> combs;
        vector<ll> temp;

        for (ll i = 0; i < n; ++i) {
            temp.push_back(i);
            if (i >= k) {
                temp.erase(temp.begin());
            }
            debug(i + 1, temp);
            if (temp.size() == k) {
                combs.insert(make_pair(items[temp[0]], temp));
            }
        }
        temp = {n - 1};
        combs.insert(make_pair(items[temp[0]], temp));
        debug(combs);
        set<ll> used;
        for (auto &par : combs) {
            if (p >= par.first) {
                bool invalid = 0;
                for (auto x : par.second) {
                    if (used.count(x)) {
                        invalid = 1;
                        break;
                    }
                }
                if (invalid) {
                    continue;
                }
                for (auto x : par.second) {
                    used.insert(x);
                    ans.push_back(x);
                }
                p -= par.first;
            }
        }
        // ll i = 0;
        // while (p > -1 && i < n) {
        //     debug(i, n, p, items[i]);
        //     if (items[i] <= p) {
        //         if (i + k <= n) {
        //             if (items[i] + items[i + k] <= p) {
        //                 p -= items[i];
        //                 for (ll j = 0; j < k; ++j, ++i) {
        //                     ans.push_back(items[i]);
        //                 }
        //                 i--;
        //             }
        //         } else {
        //             p -= items[i];
        //             ans.push_back(items[i]);
        //         }
        //     }

        //     i++;

        //     // debug(i, n, p, items[i]);
        //     debug(ans);
        //     // i++;
        // }

        debug(ans);
        cout << ans.size() << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
