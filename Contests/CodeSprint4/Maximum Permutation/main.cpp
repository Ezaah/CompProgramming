#include <bits/stdc++.h>
template <typename RandomIt1> class kmp_searcher {
  using diff_t = std::ptrdiff_t;
  RandomIt1 pattern_; // Iterator to the first element of the pattern.
  std::vector<diff_t> mismatch_; // Table to skip back on mismatch

public:
  kmp_searcher(RandomIt1 p_first, RandomIt1 p_last)
      : pattern_{p_first}, mismatch_(p_last - p_first + 1) {
    assert(p_first != p_last);
    mismatch_[0] = -1;
    for (diff_t p_pos = 0, matched = -1; p_pos < pattern_length();) {
      while (matched >= 0 && pattern_[p_pos] != pattern_[matched])
        matched = mismatch_[matched];
      mismatch_[++p_pos] = ++matched;
    }
  }

  diff_t pattern_length() const { return mismatch_.size() - 1; }

  template <typename RandomIt2>
  RandomIt2 operator()(RandomIt2 first, RandomIt2 last) const {
    diff_t matched = 0;
    while (first != last) {
      while (matched >= 0 && *first != pattern_[matched])
        matched = mismatch_[matched];
      ++first;
      ++matched;
      if (matched == pattern_length())
        return first - matched;
    }
    return last;
  }
};

template <typename RandomIt>
kmp_searcher<RandomIt> make_kmp_searcher(RandomIt p_first, RandomIt p_last) {
  return kmp_searcher<RandomIt>(p_first, p_last);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t tests;
  std::cin >> tests;
  for (size_t i = 0; i < tests; i++) {
    std::string original, match;
    std::cin >> original >> match;
    std::vector<bool> chosen(original.size());
    std::string permutation;
    std::map<std::string, bool> permutations;
    size_t max_val = 0;
    std::string max_perm;

    std::function<void()> search;
    search = [&]() {
      if (permutation.size() == original.size()) {
        if (permutations.find(permutation) != permutations.end())
          return;
        permutations.emplace(permutation, true);
        auto finder = make_kmp_searcher(permutation.begin(), permutation.end());
        size_t pos = 0;
        size_t cnt = 0;
        while (pos < match.size()) {
          pos = std::distance(match.begin(),
                              finder(match.begin() + pos, match.end()));
          if (pos == match.size()) {
            break;
          }
          ++pos;
          ++cnt;
        }
        if (cnt > max_val) {
          max_val = cnt;
          max_perm = permutation;
        } else if (cnt == max_val) {
          max_perm = std::min(max_perm, permutation);
        }
      } else {
        for (size_t i = 0; i < original.size(); i++) {
          if (chosen[i])
            continue;
          chosen[i] = true;
          permutation.push_back(original[i]);
          search();
          chosen[i] = false;
          permutation.pop_back();
        }
      }
    };
    search();

    if (max_val) {
      std::cout << max_perm << "\n";
    } else {
      std::cout << "-1\n";
    }
  }
}
