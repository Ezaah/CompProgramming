#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;
vector<sizet> KMP(vector<sizet> &S, vector<sizet> &K) {
  vector<sizet> T(K.size() + 1, -1);
  vector<sizet> matches;

  if (K.size() == 0) {
    matches.push_back(0);
    return matches;
  }

  for (sizet i = 1; i <= K.size(); i++) {
    sizet pos = T[i - 1];
    while (pos != -1 && K[pos] != K[i - 1])
      pos = T[pos];
    T[i] = pos + 1;
  }

  sizet sp = 0;
  sizet kp = 0;
  while (sp < S.size()) {
    while (kp != -1 && (kp == K.size() || K[kp] != S[sp]))
      kp = T[kp];
    kp++;
    sp++;
    if (kp == K.size())
      matches.push_back(sp - K.size());
  }

  return matches;
}
void printer(vector<long long> &arr) {
  for (auto &i : arr) {
    cout << i << " ";
  }
  cout << endl;
}
int main() {
  sizet n, w;
  cin >> n >> w;

  vector<sizet> original_n(n);
  vector<sizet> original_w(w);
  vector<sizet> text(n - 1);
  vector<sizet> pattern(w - 1);

  for (sizet i = 0; i < n; i++) {
    cin >> original_n[i];
    if (i > 0) {
      text[i - 1] = original_n[i - 1] - original_n[i];
    }
  }

  for (sizet i = 0; i < w; i++) {
    cin >> original_w[i];
    if (i > 0) {
      pattern[i - 1] = original_w[i - 1] - original_w[i];
    }
  }
  if (pattern.size() == 0) {
    cout << text.size() + 1 << "\n";
    return 0;
  }

  cout << KMP(text, pattern).size() << "\n";
}
