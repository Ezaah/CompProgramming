#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet n, m;
  cin >> n >> m;
  printf("%.1f\n", (n - m - 1) * 0.5 + m);
}
