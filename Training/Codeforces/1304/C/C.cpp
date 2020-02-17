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
struct Customer {
    ll time;
    ll low;
    ll high;

    // bool operator<(Customer other) {
    //     if (other.time == time) {
    //         if (other.low == low) {
    //             return high < other.high;
    //         }
    //         return low < other.low;
    //     }
    //     return time < other.time;
    // }
};

string to_string(Customer a) {
    return "{" + to_string(a.time) + ", " + to_string(a.low) + ", " + to_string(a.high) + "}";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<Customer> clients(n);
        for (Customer &x : clients) {
            cin >> x.time >> x.low >> x.high;
        }
        map<ll, pair<ll, ll>> ranges;
        bool impossible = 0;
        for (Customer &x : clients) {
            if (ranges.count(x.time) == 1) {
                if (x.low > ranges[x.time].second || ranges[x.time].first > x.high) {
                    impossible = 1;
                    break;
                }
                ranges[x.time] = make_pair(max(ranges[x.time].first, x.low), min(ranges[x.time].second, x.high));
            } else {
                ranges.insert(make_pair(x.time, make_pair(x.low, x.high)));
            }
        }
        debug(ranges);

        if (impossible) {
            cout << "NO\n";
            continue;
        }
        ll prev_t = 0;
        ll prev_r = m;
        for (auto &elem : ranges) {

            ll deltat = (elem.first - prev_t);
            ll deltar = elem.second.first - prev_r;
            bool high = 0;
            if (prev_r > elem.second.second) {
                deltar = prev_r - elem.second.second;
                high = 1;
            }
            debug(deltat, deltar, prev_t, prev_r);
            if (prev_r <= elem.second.second && prev_r >= elem.second.first) {
                prev_t = elem.first;
                auto sig = next(&elem);
                if (prev_r > sig->second.second) {
                    deltar = prev_r - elem.second.first;
                    prev_r -= min(deltat, deltar);
                } else {
                    deltar = elem.second.second - prev_r;
                    prev_r += min(deltat, deltar);
                }
                continue;
            }

            if (deltat >= deltar) {
                prev_t = elem.first;
                prev_r = elem.second.first;
                if (high) {
                    prev_r = elem.second.second;
                }
            } else {
                impossible = 1;
                break;
            }
        }

        if (impossible) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
