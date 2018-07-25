#include <iostream>
#include <vector>
using namespace std;
typedef long long sizet;
vector<int> KMP(string S, string K) {
  vector<int> T(K.size() + 1, -1);
  vector<int> matches;

  if (K.size() == 0) {
    matches.push_back(0);
    return matches;
  }

  for (int i = 1; i <= K.size(); i++) {
    int pos = T[i - 1];
    while (pos != -1 && K[pos] != K[i - 1])
      pos = T[pos];
    T[i] = pos + 1;
  }

  int sp = 0;
  int kp = 0;
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sizet n;
  string p, s;
  while (cin >> n >> p >> s) {
    vector<int> matches(KMP(s, p));
    for (sizet i = 0; i < matches.size(); ++i) {
      cout << matches[i] << "\n";
    }
    if (matches.size() != 0)
      cout << "\n";
  }

  return 0;
}
