#include <bits/stdc++.h>

int main() {
  size_t length;
  std::cin >> length;
  std::vector<size_t> price_table(length);
  for (size_t i = 0; i < length; i++) {
    std::cin >> price_table[i];
  }
  std::vector<long long int> calc_table(length + 1, -1);

  std::function<size_t(size_t)> rodcutter;
  rodcutter = [&](size_t n) {
    if (calc_table[n] != -1) {
      return calc_table[n];
    }
    size_t max = price_table[n - 1];
    for (size_t i = 1; i < n; i++) {
      max = std::max(max, price_table[i - 1] + rodcutter(n - i));
    }
    calc_table[n] = max;
    return calc_table[n];
  };
  rodcutter(length);

  for (size_t i = 1; i < calc_table.size(); i++) {
    std::cout << i << " =>  " << calc_table[i] << "\n";
  }
}
