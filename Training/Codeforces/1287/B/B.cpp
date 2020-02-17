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

    int n, k;
    cin >> n >> k;
    vector<string> cards(n);
    set<string> finder;
    for (string &x : cards) {
        cin >> x;
        finder.insert(x);
    }

    if (n < 3) {
        cout << "0\n";
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string missing = "";
            for (int h = 0; h < k; ++h) {
                if (cards[i][h] == cards[j][h]) {
                    missing += cards[i][h];
                } else {
                    if (cards[i][h] == 'S' && cards[j][h] == 'E') {
                        missing += 'T';
                    } else if (cards[i][h] == 'S' && cards[j][h] == 'T') {
                        missing += 'E';
                    } else if (cards[i][h] == 'E' && cards[j][h] == 'S') {
                        missing += 'T';
                    } else if (cards[i][h] == 'E' && cards[j][h] == 'T') {
                        missing += 'S';
                    } else if (cards[i][h] == 'T' && cards[j][h] == 'E') {
                        missing += 'S';
                    } else if (cards[i][h] == 'T' && cards[j][h] == 'S') {
                        missing += 'E';
                    }
                }
            }
            debug(cards[i], cards[j], missing);
            if (finder.count(missing)) {
                ans++;
            }
        }
    }

    cout << ans / 3 << "\n";
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
