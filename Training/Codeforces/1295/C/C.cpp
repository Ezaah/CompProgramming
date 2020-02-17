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
        string s, t;
        cin >> s >> t;

        ll cnt = 0;

        set<pair<char, ll>> positions;
        set<char> letters;
        for (ll i = 0; i < s.size(); ++i) {
            letters.insert(s[i]);
            positions.insert(make_pair(s[i], i));
        }

        ll last = s.size();
        // debug(positions);
        for (ll i = 0; i < t.size(); ++i) {
            // debug(i);
            if (letters.count(t[i]) == 0) {
                cnt = -1;
                break;
            }
            auto pos = positions.lower_bound(make_pair(t[i], last + 1));
            // debug(*pos, last, t[i], cnt);
            if (pos == positions.end() || t[i] != pos->first) {
                cnt++;
                pos = positions.lower_bound(make_pair(t[i], -1));
            }
            // debug(*pos, last, t[i], cnt);

            last = pos->second;
        }

        // while(pos < t.size()){
        //     bool found = 0;
        //     for(ll i = 0; i < s.size(); ++i){
        //         if(s[i] == t[pos]){
        //             pos++;
        //             found=1;
        //         }
        //     }
        //     if(found){
        //         cnt++;
        //     }else{
        //         cnt = -1;
        //         break;
        //     }
        // }

        cout << cnt << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
