#include <bits/stdc++.h>
using namespace std;
// reescribir long long para hacerlo mas corto :D
typedef long long sizet;

int main() {
  // Optimizacion de inputs
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string S;
  cin >> S;
  vector<char> V;
  for (char &c : S) {
    if (V.size() == 0) {
      V.push_back(c);
    } else if (V.back() == c) {
      V.pop_back();
    } else {
      V.push_back(c);
    }
  }
  if (V.size() == 0) {
    cout << "Yes"
         << "\n";
  } else {
    cout << "No"
         << "\n";
  }

  return 0;
}
