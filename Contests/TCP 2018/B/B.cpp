#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

sizet fast_pow(sizet base, sizet expo) {
  sizet result = 1;
  while (expo > 0) {
    if (expo % 2) {
      result *= base;
    }
    base *= base;
    expo /= 2;
  }
  return result;
}
sizet friends_needed(sizet dist, sizet run) {
  double delta = run - dist;
  return ceil(log2(run / delta));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet dist, good, good_run, normal, normal_run;
  cin >> dist >> good >> good_run >> normal >> normal_run;
  sizet friends = 0;
  if (good_run > dist) {
    sizet k = friends_needed(dist, good_run);
    if (k <= good) {
      cout << k << "\n";
      return 0;
    }
    friends += good;
    dist = fast_pow(2, good) * dist - good_run * (fast_pow(2, good) - 1);
  }

  if (normal_run > dist) {
    sizet k = friends_needed(dist, normal_run);
    if (k <= normal) {
      cout << friends + k << "\n";
    } else {
      cout << "-1\n";
    }
  } else if (dist > 0) {
    cout << "-1\n";
  }
}
