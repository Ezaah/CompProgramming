#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet tests;
  scanf("%lld", &tests);
  while (tests--) {
    sizet a, b, n, s;
    scanf("%lld%lld%lld%lld", &a, &b, &n, &s);

    for (sizet i = 0; i < a; ++i) {
      // printf("%lld: %lld\n", i, s);
      if (s - n < 0) {
        break;
      }
      s -= n;
    }
    if (s == 0 || s <= b) {
      puts("YES");
    } else if (s > b) {
      puts("NO");
    }
  }
}
