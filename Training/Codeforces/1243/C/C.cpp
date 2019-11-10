#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T> T mod_add(T a, T b, T m) {
  assert(a >= 0 && a < m);
  assert(b >= 0 && b < m);
  if (a < m - b)
    return a + b;
  return a - (m - b);
}
template <typename T> T gcd(T a, T b) {
  T tmp;
  while (b)
    tmp = b, b = a % b, a = tmp;
  return a < 0 ? -a : a;
}
template <typename T> T mod_mul(T a, T b, T m) {
  assert(a >= 0 && a < m);
  assert(b >= 0 && b < m);
  T result = 0;
  while (b > 0) {
    if (b % 2 == 1)
      result = mod_add(result, a, m);
    a = mod_add(a, a, m);
    b /= 2;
  }
  return result;
}

template <typename T> T mod_pow(T base, T exp, T m) {
  assert(base >= 0 && base < m);
  assert(exp >= 0);
  if (m == 1)
    return 0;
  T result = 1; // Since m > 1, then 1 == 1 % m
  while (exp > 0) {
    if (exp % 2 == 1)
      result = mod_mul(result, base, m);
    base = mod_mul(base, base, m);
    exp /= 2;
  }
  return result;
}

template <typename T> bool miller_rabin_primality_test(const T n) {
  if (n == 2)
    return true;
  if (n < 2 || n % 2 == 0)
    return false;
  // Write n − 1 as 2^s*d (with d odd)
  T d = n - 1;
  size_t s = 0;
  while (d % 2 == 0)
    d /= 2, ++s;

  auto reveals_compositeness = [n, s, d](const T a) {
    assert(a >= 2 && a < n && "The witness is outside range");
    T x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1)
      return false;
    for (size_t r = 1; r < s && x != 1; ++r) {
      x = mod_mul(x, x, n);
      if (x == n - 1)
        return false;
    }
    return true;
  };
  auto test_with = [&](std::initializer_list<T> witnesses) {
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

template <typename T> T pollard_rho_factor(const T n) {
  auto find_factor = [n](const T c) {
    auto abs_diff = [](T x, T y) { return x < y ? y - x : x - y; };
    unsigned long power = 1, lam = 1;
    T x = 2, x_fixed = 2;
    T factor = 1;
    while (factor == 1) {
      if (power == lam) {
        x_fixed = x, power *= 2, lam = 0;
      }
      x = mod_add(mod_mul(x, x, n), c, n);
      ++lam;
      factor = gcd(abs_diff(x, x_fixed), n);
    }
    return factor;
  };
  T step = 0;
  T factor = n;
  while (factor == n) {
    ++step;
    factor = find_factor(step);
  }
  return factor;
}

template <typename T, typename F1, typename F2>
std::vector<T> find_prime_factors(T n, F1 is_prime, F2 get_factor) {
  std::vector<T> primes;
  std::stack<T> stack;
  if (n > 1)
    stack.push(n);
  while (!stack.empty()) {
    n = stack.top();
    stack.pop();
    if (is_prime(n))
      primes.push_back(n);
    else {
      const T d = get_factor(n);
      stack.push(d);
      stack.push(n / d);
    }
  }
  std::sort(primes.begin(), primes.end()); // Sorting is optional.
  return primes;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> primes =
      find_prime_factors(n, [](ll n) { return miller_rabin_primality_test(n); },
                         [](ll n) { return pollard_rho_factor(n); });

  auto last = unique(primes.begin(), primes.end());
  primes.erase(last, primes.end());
  if (primes.size() > 1) {
    cout << "1\n";
  } else if (primes.size() == 1) {
    cout << primes[0] << "\n";
  } else {
    cout << n << "\n";
  }
}
