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
        int n;
        cin >> n;
        vector<char> seq(n);
        for (char &x : seq) {
            cin >> x;
        }

        map<pair<ll, ll>, ll> positions;
        ll min_dist = n + 1;
        pair<ll, ll> pos = make_pair(0, 0);
        positions[pos] = 0;
        pair<ll, ll> ij;
        for (ll i = 0; i < n; ++i) {
            if (seq[i] == 'L') {
                pos.first--;
            }

            if (seq[i] == 'R') {
                pos.first++;
            }

            if (seq[i] == 'D') {
                pos.second--;
            }

            if (seq[i] == 'U') {
                pos.second++;
            }
            debug(pos, positions, ij);
            if (positions.count(pos) == 1) {
                if (min_dist > i - positions[pos]) {
                    min_dist = i - positions[pos];
                    ij = make_pair(positions[pos], i);
                }
            }
            positions[pos] = i + 1;
        }

        if (min_dist == n + 1) {
            cout << "-1\n";
        } else {
            cout << ij.first + 1 << " " << ij.second + 1 << "\n";
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
