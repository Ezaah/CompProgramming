#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet n;
  cin >> n;
  vector<sizet> votes(3);
  for (sizet i = 0; i < n; ++i) {
    char vote;
    cin >> vote;
    votes[0] += 1 && vote == 'P';
    votes[1] += 1 && vote == 'N';
    votes[2] += 1 && vote == 'I';
  }
  if (votes[0] + votes[2] > votes[1] && votes[1] + votes[2] >= votes[0]) {
    cout << "INDECISOS\n";
  } else if (votes[1] >= votes[0] + votes[2]) {
    cout << "NO\n";
  } else {
    cout << "SI\n";
  }
}
