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

    int n, m;
    cin >> n >> m;
    vector<string> names(n * m);
    vector<string> s(n);
    vector<string> t(m);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i < n * m; ++i) {
        names[i] = s[i % n] + t[i % m];
    }

    debug(names);
    int q;
    cin >> q;
    while (q--) {
        int year;
        cin >> year;

        cout << names[(year - 1) % names.size()] << "\n";
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
