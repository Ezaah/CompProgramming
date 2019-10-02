#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

template <typename T>
std::tuple<T, T, T> extended_euclid(const T a, const T b) {
  static_assert(std::is_signed<T>::value, "");

  T r = b, old_r = a;
  T s = 0, old_s = 1;
  T t = 1, old_t = 0;
  while (r != 0) {
    const T quotient = old_r / r;
    T tmp;
    tmp = r, r = old_r - quotient * r, old_r = tmp;
    tmp = s, s = old_s - quotient * s, old_s = tmp;
    tmp = t, t = old_t - quotient * t, old_t = tmp;
  }
  return old_r >= 0 ? std::make_tuple(old_r, old_s, old_t)
                    : std::make_tuple(-old_r, -old_s, -old_t);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  double angle;
  cin >> angle;
  sizet ang = angle * 100;
  auto values = extended_euclid(ang, (sizet)36000);

  cout << get<1>(values) << " " << get<2>(values)<< "\n";
}
