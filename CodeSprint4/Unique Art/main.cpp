#include <bits/stdc++.h>
typedef long long int size_T;
struct node_function : std::binary_function<std::set<size_T>, std::set<size_T>,
                                            std::set<size_T>> {
  const std::set<size_T> operator()(const std::set<size_T> &a,
                                    const std::set<size_T> &b) const {
    std::set<size_T> ret;
    for (auto &node : a) {
      ret.insert(node);
    }
    for (auto &node : b) {
      if (ret.find(node) != ret.end()) {
        ret.erase(node);
      } else {
        ret.insert(node);
      }
    }
    return ret;
  }
};

template <typename T, typename BinaryOp> class segment_tree {
  size_t num_elems{};
  BinaryOp op{};
  std::vector<T> tree{};

public:
  template <typename ForwardIt>
  void assign(ForwardIt first, ForwardIt last, BinaryOp comb = BinaryOp()) {
    num_elems = std::distance(first, last);
    op = comb;
    tree.resize(2 * num_elems);
    if (!num_elems)
      return;
    std::copy(first, last, tree.begin() + num_elems);
    for (size_t i = num_elems - 1; i > 0; --i)
      tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
  }

  void modify(size_t pos, const T &new_value) {
    tree[pos += num_elems] = new_value;
    for (; pos > 1; pos >>= 1)
      tree[pos >> 1] = op(tree[pos], tree[pos ^ 1]);
  }

  T accumulate(size_t l, size_t r) const {
    T ans = at(l++);
    for (l += num_elems, r += num_elems; l < r; l >>= 1, r >>= 1) {
      if ((l & 1) != 0)
        ans = op(ans, tree[l++]);
      if ((r & 1) != 0)
        ans = op(ans, tree[--r]);
    }
    return ans;
  }

  const T &at(size_t pos) const { return tree[num_elems + pos]; }

  size_t size() const { return num_elems; }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t paintings_amount;
  std::cin >> paintings_amount;
  std::vector<std::set<size_T>> paintings(paintings_amount);
  for (size_t i = 0; i < paintings_amount; i++) {
    size_T type;
    std::cin >> type;
    paintings[i].insert({type});
  }
  segment_tree<std::set<size_T>, node_function> querier;
  querier.assign(paintings.begin(), paintings.end());
  size_t queries;
  std::cin >> queries;
  for (size_t i = 0; i < queries; i++) {
    size_t a, b;
    std::cin >> a >> b;
    a--;
    auto ans = querier.accumulate(a, b);
    std::cout << ans.size() << "\n";
  }
}
