#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

bool is_prime(sizet x) {
  for (sizet i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<sizet> common_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  sizet tests;
  scanf("%lld", &tests);
  while (tests--) {
    sizet n;
    scanf("%lld", &n);
    size_t i = 0;
    while (is_prime(n - common_primes[i]) && i < common_primes.size()) {
      i++;
    }
    if (i == common_primes.size()) {
      puts("-1");
      continue;
    }
    printf("%lld %lld\n", common_primes[i], n - common_primes[i]);
  }
}
