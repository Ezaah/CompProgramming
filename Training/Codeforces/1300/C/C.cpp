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

string to_string(bitset<32> a) {
    return "{" + a.to_string() + "}";
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
int func(int a, int b) {
    return (a | b) - b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;

    ll n;
    cin >> n;
    vector<ll> numbers(n);
    for (ll &x : numbers) {
        cin >> x;
    }

    vector<ll> ans = numbers;
    map<int, vector<pair<ll, ll>>, std::greater<int>> pos;
    for (int i = 63; ~i; i--) {
        for (ll j = 0; j < n; ++j) {
            if ((numbers[j] >> i) & 1) {
                pos[i].push_back(make_pair(numbers[j], j));
            }
        }
    }
    bool found = 0;
    ll index = 0;
    for (auto &par : pos) {
        if (par.second.size() == 1) {
            ans.clear();
            auto number = par.second.front();
            index = number.second;
            ans.push_back(number.first);
            found = 1;
            break;
        }
    }
    if (found) {
        for (ll j = 0; j < n; ++j) {
            if (j == index) {
                continue;
            }
            ans.push_back(numbers[j]);
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
