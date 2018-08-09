#include <bits/stdc++.h>
using namespace std;
// reescribir long long para hacerlo mas corto :D
typedef long long sizet;
void imprime(vector<sizet> &V) {
  for (sizet i = 0; i < V.size(); i++) {
    cout << V[i] << " ";
  }
  cout << "\n";
}
void build(vector<sizet> V, vector<sizet> &T) {
  sizet N = V.size();
  for (sizet i = 0; i < N; i++) {
    T[N + i] = V[i];
  }

  for (sizet i = N - 1; i > 0; --i) {
    T[i] = T[i << 1] + T[i << 1 | 1];
  }
}
sizet query(sizet l, sizet r, vector<sizet> &T) {
  sizet res = 0;
  sizet n = T.size() / 2;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      res += T[l++];
    if (r & 1)
      res += T[--r];
  }
  return res;
}
void modify(sizet p, sizet value, vector<sizet> &T) {
  sizet n = T.size() / 2;
  for (T[p += n] = value; p > 1; p >>= 1) {
    T[p >> 1] = T[p] + T[p ^ 1];
  }
}
int main() {
  // Optimizacion de inputs
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sizet N;
  cin >> N;
  sizet k = 1;
  while (N) {
    vector<sizet> A(N);
    for (sizet i = 0; i < N; ++i) {
      sizet v;
      cin >> v;
      A[i] = v;
    }
    vector<sizet> ST(2 * N);
    build(A, ST);
    vector<sizet> ans;
    string op;
    cin >> op;
    while (op != "END") {
      if (op == "M") {
        sizet i, j;
        cin >> i >> j;
        sizet a = query(i - 1, j, ST);
        ans.push_back(a);

      } else {
        sizet i, j;
        cin >> i >> j;
        A[i - 1] = j;
        modify(i - 1, j, ST);
      }
      cin >> op;
    }
    cout << "Case " << k << ":\n";
    for (sizet i = 0; i < ans.size(); i++) {
      cout << ans[i] << "\n";
    }
    k++;

    cin >> N;
    if (N) {
      cout << "\n";
    }
  }

  return 0;
}
