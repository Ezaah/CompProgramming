#include <bits/stdc++.h>
using namespace std;
// reescribir long long para hacerlo mas corto :D
typedef long long sizet;

sizet gcd(sizet a, sizet b) {
  sizet tmp;
  while (b)
    tmp = b, b = a % b, a = tmp;
  return a < 0 ? -a : a;
}

sizet lcm(sizet a, sizet b) {
  if (a == 0 || b == 0)
    return 0;
  sizet ans = a / gcd(a, b) * b;
  return ans < 0 ? -ans : ans;
}

int main() {
  // Optimizacion de inputs
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sizet x, y, a, b;
  cin >> x >> y >> a >> b;
  sizet val = lcm(x, y);
  sizet cont = (sizet)(b / val) - (sizet)(a - 1) / val;
  cout << cont << "\n";

  return 0;
}
