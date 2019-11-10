#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string name;
  cin >> name;

  sort(name.begin(), name.end());
  auto last = unique(name.begin(), name.end());
  name.erase(last, name.end());

  (name.size() % 2 == 0) ? cout << "CHAT WITH HER!\n" : cout << "IGNORE HIM!\n";
}
