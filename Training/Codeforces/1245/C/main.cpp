#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

sizet mod_add(sizet a, sizet b, sizet mod = 1e9 + 7) {
  if (a < mod - b) {
    return a + b;
  }
  return a - (mod - b);
}

sizet mod_mul(sizet a, sizet b, sizet mod = 1e9 + 7) {
  sizet sum = 0;
  while (b > 0) {
    if (b % 2 == 1) {
      sum = mod_add(sum, a, mod);
    }
    a = mod_add(a, a, mod);
    b /= 2;
  }
  return sum;
}

void print_arr(vector<sizet> a) {
  for (auto x : a) {
    cout << x << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string word;
  cin >> word;

  vector<sizet> consectives;
  for (sizet i = 0; i < (sizet)word.size(); ++i) {
    if (word[i] == 'm' || word[i] == 'w') {
      puts("0");
      return 0;
    }
  }

  for (sizet i = 0; i < (sizet)word.size(); ++i) {
    if (word[i] == 'u') {
      sizet cnt = 1;
      i++;
      while (i < word.size() && word[i] == 'u') {
        cnt++;
        i++;
      }

      consectives.push_back(cnt);
    }
    if (word[i] == 'n') {
      sizet cnt = 1;
      i++;
      while (i < word.size() && word[i] == 'n') {
        cnt++;
        i++;
      }

      consectives.push_back(cnt);
    }
  }

  if (consectives.empty()) {
    puts("1");
    return 0;
  }
  sort(consectives.rbegin(), consectives.rend());
  vector<sizet> fibs(consectives[0] + 2);

  fibs[0] = 0;
  fibs[1] = 1;

  for (sizet i = 2; i < (sizet)fibs.size(); ++i) {
    fibs[i] = mod_add(fibs[i - 1], fibs[i - 2]);
  }

  sizet prod = 1;
  for (sizet x : consectives) {
    prod = mod_mul(fibs[x + 1], prod);
  }

  printf("%lld\n", prod);
}
