#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

/*
 *
 * EULERIAN NUMBER FORMULAR:
 *	A(n,m) = (n - m)*A(n - 1, m - 1) + (m + 1)*A(n - 1, m)
 *  A(n, 0) = 1
 *  A(0, m) = 0
 */

sizet mod_add(sizet a, sizet b, sizet m = 1001113) {
  if (a < m - b)
    return a + b;
  return a - (m - b);
}
sizet mod_mul(sizet a, sizet b, sizet m = 1001113) {
  sizet ret = 0;
  while (b > 0) {
    if (b % 2) {
      ret = mod_add(ret, a, m);
    }
    a = mod_add(a, a, m);
    b /= 2;
  }
  return ret;
}

struct data_set {
  sizet number;
  sizet order;
  sizet count;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  sizet sets_amount;
  cin >> sets_amount;
  vector<data_set> data_sets;
  sizet maxm = 0, maxn = 0;
  for (sizet i = 0; i < sets_amount; ++i) {
    sizet number, order, count;
    cin >> number >> order >> count;
    maxm = max(maxm, count);
    maxn = max(maxn, order);
    data_sets.push_back({number, order, count});
  }

  vector<vector<sizet>> data(maxn + 1, vector<sizet>(maxm + 1));
  for (sizet i = 1; i <= maxn; ++i) {
    data[i][0] = 1;
  }
  for (sizet i = 1; i <= maxn; ++i) {
    for (sizet j = 1; j <= maxm; ++j) {
      //    cout << "calculating A(" << i << "," << j << ")" << endl;
      data[i][j] = mod_add(mod_mul((i - j), data[i - 1][j - 1]),
                           mod_mul((j + 1), data[i - 1][j]));
    }
  }

  for (auto &sets : data_sets) {
    cout << sets.number << " " << data[sets.order][sets.count] << "\n";
  }
}
