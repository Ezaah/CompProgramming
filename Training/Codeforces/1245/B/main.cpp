#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

void print_arr(vector<sizet> a) {
  for (auto x : a) {
    printf("%lld ", x);
  }
  printf("\n");
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet tests;
  cin >> tests;
  while (tests--) {
    sizet n;
    cin >> n;
    vector<sizet> alice(3);
    vector<sizet> bob(3);
    vector<char> bob_seq(n);
    for (sizet i = 0; i < 3; ++i) {
      cin >> alice[i];
    }

    for (sizet i = 0; i < n; ++i) {
      cin >> bob_seq[i];
      if (bob_seq[i] == 'R') {
        bob[0]++;
      } else if (bob_seq[i] == 'P') {
        bob[1]++;
      } else {
        bob[2]++;
      }
    }

    sizet rock_wins = min(alice[0], bob[2]);
    sizet paper_wins = min(alice[1], bob[0]);
    sizet scissor_wins = min(alice[2], bob[1]);

    sizet total_wins = rock_wins + scissor_wins + paper_wins;
    if (2 * total_wins < n) {
      cout << "NO\n";
      continue;
    }

    vector<char> alice_seq(n, 'A');

    for (sizet i = 0; i < n; ++i) {
      if (bob_seq[i] == 'R' && alice[1] > 0) {
        alice_seq[i] = 'P';
        alice[1]--;
      }
      if (bob_seq[i] == 'P' && alice[2] > 0) {
        alice_seq[i] = 'S';
        alice[2]--;
      }

      if (bob_seq[i] == 'S' && alice[0] > 0) {
        alice_seq[i] = 'R';
        alice[0]--;
      }
    }

    for (sizet i = 0; i < n; ++i) {
      if (alice_seq[i] != 'A') {
        continue;
      }

      if (alice[0] > 0) {
        alice_seq[i] = 'R';
        alice[0]--;
      } else if (alice[1] > 0) {
        alice_seq[i] = 'P';
        alice[1]--;
      } else {
        alice_seq[i] = 'S';
        alice[2]--;
      }
    }

    cout << "YES\n";
    for (char chr : alice_seq) {
      cout << chr;
    }
    cout << "\n";
  }
}
