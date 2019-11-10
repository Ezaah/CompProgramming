#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet n;
  scanf("%lld", &n);
  sizet i = 1;
  sizet j = n;
  sizet min_val = 1e9;
  while (i <= j) {
    if (n % i == 0) {
      j = n / i;
      //   printf("%lld %lld\n", i, j);
      min_val = min(min_val, 2 * j + 2 * i);
    }
    ++i;
  }
  printf("%lld\n", min_val);
}
