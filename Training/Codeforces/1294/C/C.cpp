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
ll mod_add(ll a, ll b, ll m) {
    if (a < m - b) {
        return a + b;
    }
    return a - (m - b);
}

ll mod_mul(ll a, ll b, ll m) {
    ll res = 0;
    while (b > 0) {
        if (b % 2 == 1) {
            res = mod_add(res, a, m);
        }
        a = mod_add(a, a, m);
        b /= 2;
    }
    return res;
}

ll mod_pow(ll base, ll exp, ll m) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = mod_mul(res, base, m);
        }
        base = mod_mul(base, base, m);
        exp /= 2;
    }
    return res;
}

ll isqrt(ll x) {
    using U = make_unsigned<ll>::type;
    constexpr U max_ans = (U(1) << (numeric_limits<U>::digits / 2)) - U(1);
    U ans = min(max_ans, static_cast<U>(sqrt(x)));
    while (ans * ans > U(x)) {
        --ans;
    }
    while (ans < max_ans && (ans + U(1)) * (ans + U(1)) <= U(x)) {
        ++ans;
    }

    return ans;
}

bool is_square(ll x) {
    auto brute_check = [x] {
        ll t = isqrt(x);
        return t * t == x;
    };
    ll d = x % 16;
    return (d == 0 || d == 1 || d == 4 || d == 9) && brute_check();
}

ll get_factor(const ll n) {
    auto find_factor = [n](const ll k) -> ll {
        const ll sqrt_kn = isqrt(k * n);
        ll p = sqrt_kn, old_p;
        ll q = (k * n - p * p), old_q = 1;
        if (q == 0)
            return k == 1 ? sqrt_kn : 1;
        auto iterate = [&] {
            old_p = p;
            ll b = (sqrt_kn + old_p) / q, tmp;
            p = b * q - old_p;
            tmp = q, q = old_q + b * (old_p - p), old_q = tmp;
        };
        for (size_t i = 1; i % 2 || !is_square(q); ++i)
            iterate();
        const ll sqrt_q = isqrt(q);
        const ll b = (sqrt_kn - p) / sqrt_q;
        p = b * sqrt_q + p;
        old_q = sqrt_q, q = (k * n - p * p) / old_q;
        do
            iterate();
        while (p != old_p);
        return __gcd(n, p);
    };
    const ll max_k = std::numeric_limits<ll>::max() / n;
    for (ll k = 1; k <= max_k; ++k) {
        const ll f = find_factor(k);
        if (f != 1 && f != n)
            return f;
    }
    throw std::overflow_error("Can't use a larger multiplier.");
}

bool is_prime(const ll n) {
    if (n == 2)
        return true;
    if (n < 2 || n % 2 == 0)
        return false;
    // Write n − 1 as 2^s*d (with d odd)
    ll d = n - 1;
    size_t s = 0;
    while (d % 2 == 0)
        d /= 2, ++s;

    auto reveals_compositeness = [n, s, d](const ll a) {
        assert(a >= 2 && a < n && "The witness is outside range");
        ll x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (size_t r = 1; r < s && x != 1; ++r) {
            x = mod_mul(x, x, n);
            if (x == n - 1)
                return false;
        }
        return true;
    };
    auto test_with = [&](std::initializer_list<ll> witnesses) {
        return std::none_of(witnesses.begin(), witnesses.end(),
                            reveals_compositeness);
    };

    if (n < 2047)
        return test_with({2});
    if (n < 9080191)
        return test_with({31, 73});
    if (n < 4759123141)
        return test_with({2, 7, 61}); // Until here it's enough for 32-bits ints.
    if (n < 1122004669633)
        return test_with({2, 13, 23, 1662803});
    if (n < 2152302898747)
        return test_with({2, 3, 5, 7, 11});
    if (n < 3474749660383)
        return test_with({2, 3, 5, 7, 11, 13});
    if (n < 341550071728321)
        return test_with({2, 3, 5, 7, 11, 13, 17});
    if (n < 3825123056546413051)
        return test_with({2, 3, 5, 7, 11, 13, 17, 19, 23});
    // According to sequence A014233 in OEIS, the first 12 primes taken as base
    // are enough to test numbers less than 318665857834031151167461 ~ 3.19E23.
    return test_with({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37});
}

vector<ll> find_primes(ll n) {
    vector<ll> primes;
    stack<ll> stack;
    if (n > 1) {
        stack.push(n);
    }
    while (!stack.empty()) {
        n = stack.top();
        stack.pop();
        if (is_prime(n)) {
            primes.push_back(n);
        } else {
            ll d = get_factor(n);
            stack.push(d);
            stack.push(n / d);
        }
    }

    sort(primes.begin(), primes.end());
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> primes = find_primes(n);
        if (primes.size() < 3) {
            cout << "NO\n";
            continue;
        }

        ll a = primes[0];
        ll b = primes[1];
        ll i = 2;
        while (b == a && i < primes.size()) {
            b *= primes[i];
            i++;
        }
        if (i == primes.size()) {
            cout << "NO\n";
            continue;
        }
        ll c = 1;
        for (; i < primes.size(); ++i) {
            c *= primes[i];
        }

        if (c == a || c == b) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
