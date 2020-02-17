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

    int n;
    cin >> n;

    set<int> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.insert(i + 1);
    }

    vector<int> lights(n);
    deque<pair<int, bool>> pos;
    for (int i = 0; i < n; ++i) {
        cin >> lights[i];
        if (numbers.count(lights[i])) {
            numbers.erase(lights[i]);
        }
        if (lights[i] != 0) {
            pos.push_back(make_pair(i, lights[i] % 2 == 0));
        }
    }
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    vector<int> odd, even;
    for (auto &elem : numbers) {
        if (elem % 2 == 0) {
            even.push_back(elem);
        } else {
            odd.push_back(elem);
        }
    }
    debug(odd, even, pos);
    for (int i = 0; i < n; ++i) {
        if (lights[i] != 0) {
            continue;
        }
        if (i > pos.front().first) {
            pos.pop_front();
        }
        bool Seven = 0;
        bool Eeven = 0;
        if (i != 0) {
            Seven = lights[i - 1] % 2 == 0;
        } else if (pos.size()) {
            Seven = pos.front().second;
        }
        if (i != n - 1) {
            Eeven = pos.front().second;
        } else {
            Eeven = Seven;
        }
        debug(i, lights, Seven, Eeven, pos.front());
        if (Eeven == Seven) {
            if (Seven) {
                if (even.size()) {
                    lights[i] = even.back();
                    even.pop_back();
                } else {
                    lights[i] = odd.back();
                    odd.pop_back();
                }
            } else {
                if (odd.size()) {
                    lights[i] = odd.back();
                    odd.pop_back();
                } else {
                    lights[i] = even.back();
                    even.pop_back();
                }
            }
        } else {
            if (Seven) {
                if (even.size()) {
                    lights[i] = even.back();
                    even.pop_back();
                } else {
                    lights[i] = odd.back();
                    odd.pop_back();
                }
            } else {
                if (odd.size()) {
                    lights[i] = odd.back();
                    odd.pop_back();
                } else {
                    lights[i] = even.back();
                    even.pop_back();
                }
            }
        }

        debug(i, lights);
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (lights[i] % 2 != lights[i + 1] % 2) {
            ans++;
        }
    }
    cout << ans << "\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
