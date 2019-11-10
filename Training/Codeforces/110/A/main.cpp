#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string number;
  cin >> number;

  ll lucky_digits = 0;
  for (char elem : number) {
    if (elem == '4' || elem == '7') {
      lucky_digits++;
    }
  }

  bool lucky_number = 1;
  number = to_string(lucky_digits);
  for (char elem : number) {
    if (elem != '4' && elem != '7') {
      lucky_number = 0;
      break;
    }
  }

  lucky_number ? cout << "YES\n" : cout << "NO\n";
}
