#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

void print_perm(vector<sizet> a) {
  for (auto x : a) {
    printf("%lld ", x);
  }
  puts("");
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet tests;
  scanf("%lld", &tests);
  while (tests--) {
    sizet n;
    scanf("%lld", &n);
    vector<sizet> perm(n);
    set<sizet> used;
    for (sizet i = 0; i < n; ++i) {
      scanf("%lld", &perm[i]);
    }
    used.insert(0);
    for (sizet k = 0; k < n - 1; ++k) {
      sizet min_element = n + 2;
      sizet operation = -1;
      for (sizet i = 0; i < n; ++i) {
        if (perm[i] < min_element && used.find(i) == used.end()) {
          min_element = perm[i];
          operation = i;
        }
      }
      //   printf("%lld %lld\n", min_element, operation);
      if (perm[operation - 1] > min_element) {
        used.insert(operation);
        swap(perm[operation - 1], perm[operation]);
      } else {
        used.insert(operation);
      }
    }
    for (sizet i = 0; i < n; ++i) {
      printf("%lld", perm[i]);
      if (i + 1 < n) {
        printf(" ");
      } else {
        puts("");
      }
    }
  }
}
