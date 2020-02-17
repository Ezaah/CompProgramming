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
        vector<int> digits(n);
        for (int &x : digits) {
            char a;
            cin >> a;
            x = a - '0';
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += digits[i];
        }

        debug(sum, digits);
        while (digits.back() % 2 == 0 && n > 0) {
            sum -= digits.back();
            digits.pop_back();
            n--;
        }

        debug(sum, digits);
        if (n == 0) {
            cout << "-1\n";
            continue;
        }

        while (sum % 2 != 0 && n > 1) {
            bool found = 0;
            for (int i = 0; i < n - 1; ++i) {
                debug(sum - digits[i], digits);

                if ((sum - digits[i]) % 2 == 0) {
                    sum -= digits[i];
                    n--;
                    digits.erase(digits.begin() + i);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                break;
            }
        }

        if (sum % 2 != 0) {
            cout << "-1\n";
            continue;
        }
        debug(sum, digits);
        while (digits.front() == 0 && n > 0) {
            digits.erase(digits.begin());
            n--;
        }
        if (n == 0) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            cout << digits[i];
        }
        cout << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
