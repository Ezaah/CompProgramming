#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

sizet mod_add(sizet a, sizet b, sizet mod = 1e9 + 7) {
  if (a < mod - b) {
    return a + b;
  }
  return a - (mod - b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet n, m;
  scanf("%lld%lld", &n, &m);

  // fibonacci might work, idk. too slow either way :(
  sizet fibn, fibm;
  sizet prev = 0;
  sizet actual = 1;
  for (sizet i = 1; i < n; ++i) {
    sizet test = 1;
    sizet tmp = actual;
    actual = mod_add(prev, actual);
    prev = tmp;
  }
  fibn = actual;
  prev = 0;
  actual = 1;
  for (sizet i = 1; i < m; ++i) {
    sizet tmp = actual;
    actual = mod_add(prev, actual);
    prev = tmp;
  }
  fibm = actual;
  printf("%lld %lld\n", fibn, fibm);
}
