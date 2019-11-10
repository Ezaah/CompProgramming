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

    sizet needed_a = s / n;

    // printf("needed_a: %lld\n", needed_a);
    if (needed_a > a) {
      needed_a = a;
    }
    s -= needed_a * n;
    // printf("needed_b: %lld\n", s);
    if (s > b) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
}
