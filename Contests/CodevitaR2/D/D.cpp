#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

float damage(string &command) {
  float sum = 0;
  float potency = 1;
  for (auto &chr : command) {
    if (chr == 'M') {
      potency *= 3;
    } else if (chr == 'S') {
      if (potency / 2 >= 1) {
        potency /= 2;
      }

    } else {
      sum += potency;
    }
  }
  return sum;
}

string best(string &command) {
  set<pair<sizet, string>> bests;
  string aux;
  bests.insert({1000000000000000, command});
  for (size_t i = 0; i < command.size() - 1; ++i) {
    aux = command;
    if (aux[i] == 'M') {
      swap(aux[i], aux[i + 1]);
      //    cout << aux << " " << command << " " << damage(aux) << " " <<
      //    original
      //       << endl;
      bests.insert({damage(aux), aux});
    }
  }
  return bests.begin()->second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet tests;
  cin >> tests;
  while (tests--) {
    string command;
    sizet shield;
    cin >> shield >> command;
    bool possible = 0;
    for (size_t i = 0; i < command.size() + 1; ++i) {
      // cout << i << " swaps" << endl;
      float dam = damage(command);
      if (dam <= shield) {
        possible = 1;
        cout << i << "\n";
        break;
      }
      command = best(command);
      // cout << dam << command << command.size() << endl;
      // cout << command << "\n";
    }
    if (!possible) {
      cout << "IMPOSSIBLE\n";
    }
  }
}
