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
#define RIGHT 1
#define UP 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;

    ll t;
    cin >> t;
    while (t--) {

        ll n;
        cin >> n;
        vector<pair<ll, ll>> packets(n);
        set<pair<ll, ll>> positions;
        for (auto &packet : packets) {
            cin >> packet.first >> packet.second;
            positions.insert(packet);
        }

        sort(packets.begin(), packets.end());
        ll max_x = 0;
        ll max_y = 0;
        for (ll i = 0; i < n; ++i) {
            max_x = max(max_x, packets[i].first + 1);
            max_y = max(max_y, packets[i].second + 1);
        }
        debug(max_x, max_y);
        vector<vector<pair<ll, ll>>> table(max_x, vector<pair<ll, ll>>(max_y, {-1, -1}));
        table[0][0] = {0, 0};
        for (ll i = 0; i < max_x; ++i) {
            for (ll j = 0; j < max_y; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                table[i][j].first = positions.count(make_pair(i, j));
                if (i == 0) {
                    table[i][j] = {table[i][j - 1].first + table[i][j].first, RIGHT};
                    continue;
                }

                if (j == 0) {
                    table[i][j] = {table[i - 1][j].first + table[i][j].first, UP};
                    continue;
                }

                table[i][j].first = max(table[i - 1][j].first, table[i][j - 1].first) + table[i][j].first;
                if (table[i - 1][j].first > table[i][j - 1].first) {
                    table[i][j].second = UP;
                } else {
                    table[i][j].second = RIGHT;
                }
            }
        }

        debug(table[max_x - 1][max_y - 1]);

        if (table[max_x - 1][max_y - 1].first != n) {
            cout << "NO\n";
            continue;
        }

        string directions = "";
        pair<ll, ll> pos = packets.back();
        while (table[pos.first][pos.second].second != 0) {
            if (table[pos.first][pos.second].second == UP) {
                directions += "R";
                pos.first--;
            } else {
                directions += "U";
                pos.second--;
            }
        }

        reverse(directions.begin(), directions.end());

        debug(directions);
        cout << "YES\n"
             << directions << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
