#include <bits/stdc++.h>
using namespace std;
// reescribir long long para hacerlo mas corto :D
typedef long long int sizet;

sizet mod_add(sizet a, sizet b, sizet m) {
  assert(a >= 0 && a < m);
  assert(b >= 0 && b < m);
  if (a < m - b)
    return a + b;
  return a - (m - b);
}
sizet mod_mul(sizet a, sizet b, sizet m) {
  assert(a >= 0 && a < m);
  assert(b >= 0 && b < m);
  sizet result = 0;
  while (b > 0) {
    if (b % 2 == 1)
      result = mod_add(result, a, m);
    a = mod_add(a, a, m);
    b /= 2;
  }
  return result;
}

sizet mod_pow(sizet base, sizet exp, sizet m){
	if(m==1){
		return 0;
	}
	sizet result = 1;
	while(exp > 0){
		if(exp % 2 == 1)
			result = mod_mul(result, base, m);
		base = mod_mul(base,base,m);
		exp /= 2;
	}
	return result;

}
int main() {
  // Optimizacion de inputs
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sizet T, N;
  cin >> T;
  for (sizet k = 0; k < T; ++k) {
    cin >> N;
    sizet sum = 0;
    for (sizet i = 0; i < N; ++i) {
      sizet val;
      cin >> val;
      sum = mod_add(val % 100000007, sum, 100000007);
    }
    cout << "Case " << k + 1 << ": "
         << mod_mul(mod_pow(2, N - 1, 100000007), sum, 100000007) % 100000007 << "\n";
  }

  return 0;
}
