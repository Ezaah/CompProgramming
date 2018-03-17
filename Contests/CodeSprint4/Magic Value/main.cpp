#include <bits/stdc++.h>

template <typename T> T gcd(T a, T b) {
  T tmp;
  while (b)
    tmp = b, b = a % b, a = tmp;
  return a < 0 ? -a : a;
}

size_t calc_value(size_t i, size_t j, std::vector<size_t> &values) {
  size_t ans = gcd(values[i], values[i]);
  for (size_t k = i + 1; k <= j; k++) {
    ans = gcd(ans, values[k]);
  }
  return (i + 1) * ans;
}

size_t magic_number(std::vector<size_t> &values) {
  size_t vmin = std::numeric_limits<size_t>::max();
  size_t vmax = std::numeric_limits<size_t>::min();
  std::vector<size_t> subarray;

  std::function<void(size_t)> search;
  search = [&](size_t k) {
    if (k == values.size()) {
      if (subarray.size() != 1 && subarray.size() != 2)
        return;
      size_t value = calc_value(subarray.front(), subarray.back(), values);
      vmin = std::min(vmin, value);
      vmax = std::max(vmax, value);
    } else {
      search(k + 1);
      subarray.push_back(k);
      search(k + 1);
      subarray.pop_back();
    }
  };
  search(0);
  return (vmax - vmin) * values.size();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t size;
  std::cin >> size;
  std::vector<size_t> values(size);
  for (size_t i = 0; i < size; i++) {
    std::cin >> values[i];
  }
  size_t sum = 0;
  std::vector<size_t> subset, subset_index;

  std::function<void(size_t)> search;
  search = [&](size_t k) {
    if (k == size) {
      if (subset.size() < 2)
        return;
      for (size_t i = 0; i < subset_index.size() - 1; i++) {
        if (subset_index[i] + 1 != subset_index[i + 1])
          return;
      }
      sum = ((sum % 1000000007) + (magic_number(subset) % 1000000007)) %
            1000000007;
    } else {
      search(k + 1);
      subset_index.push_back(k);
      subset.push_back(values[k]);
      search(k + 1);
      subset_index.pop_back();
      subset.pop_back();
    }
  };
  search(0);
  std::cout << sum << "\n";
}
