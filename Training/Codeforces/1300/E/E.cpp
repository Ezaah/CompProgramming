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
    vector<ll> tanks(n);
    for (ll &x : tanks) {
        cin >> x;
    }

    vector<pair<pair<ll, ll>, double>> ans;
    for (ll i = 0; i + 1 < n; ++i) {
        if (tanks[i] < tanks[i + 1]) {
            ans.push_back(make_pair(make_pair(i, i + 1), (double)tanks[i]));
        } else {
            double average = ((double)tanks[i] + tanks[i + 1]) / 2.0;
            double size = 2;
            for (ll j = i + 2; j < n; ++j) {
                if (average > tanks[j]) {
                    size++;
                    average += ((double)tanks[j] - average) / size;
                    debug(average, size);
                } else {
                    ans.push_back(make_pair(make_pair(i, j), average));
                }
            }
        }
    }
    debug(ans);
    vector<double> answer(n);
    for (auto &elem : ans) {
        for (ll i = elem.first.first; i < elem.first.second; ++i) {
            answer[i] = elem.second;
        }
    }

    cout << setprecision(7) << fixed;
    for (ll i = 0; i < n; ++i) {
        cout << answer[i] << " ";
    }
    cout << "\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
