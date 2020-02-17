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

    ll n;
    cin >> n;

    multimap<pair<ll, ll>, bool> ascents;
    multiset<pair<ll, ll>> comps;
    for (ll i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        ll maxi = -1;
        ll maxi_pos;
        ll mini = 1e9;
        ll mini_pos;
        ll last = -1;
        // vector<ll> nums(k);
        bool asc = 0;
        for (ll j = 0; j < k; ++j) {
            ll x;
            cin >> x;
            if (mini > x) {
                mini = x;
                mini_pos = j;
            }
            if (maxi < x) {
                maxi = x;
                maxi_pos = j;
            }
            if (last == -1) {
                last = x;
                continue;
            }
            debug(i, last, x, mini, maxi);
            if (last < x) {
                asc = 1;
            }
            last = x;
        }
        pair<ll, ll> seq = make_pair(mini, maxi);
        if (mini_pos > maxi_pos) {
            swap(seq.first, seq.second);
        }
        debug(seq, asc);
        comps.insert(seq);
        ascents.insert(make_pair(seq, asc));
    }

    vector<ll> accum;
    ll cnt = 0;
    for (auto elem : comps) {
        if ((*ascents.find(elem)).second) {
            cnt++;
        }
        accum.push_back(cnt);
    }
    debug(ascents);
    debug(comps);
    debug(accum);
    ll ans = 0;
    ll i = 0;
    for (auto elem : comps) {
        if ((*ascents.find(elem)).second) {
            ans += n;

        } else {

            auto last = comps.upper_bound(make_pair(elem.first, elem.first));

            ans += distance(last, comps.end()) + accum[i];
            // for (auto it = comps.begin(); it != last; ++it) {

            //     if (ascents[(*it).second]) {
            //         ans++;
            //     }
            // }
        }
        i++;
    }

    cout << ans << "\n";
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
