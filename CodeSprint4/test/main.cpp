#include <bits/stdc++.h>

int main() {
  long long int a = 65;
  long long int b = 64;
  long long int c = 1;
  size_t a_bits = (1 << (a));
  size_t b_bits = (1 << (b));
  size_t c_bits = (1 << (c));
  std::bitset<64> bitsa(a_bits);
  std::bitset<64> bitsb(b_bits);
  std::bitset<64> bitsc(c_bits);
  std::cout << bitsa.to_string() << "\n\n\n"
            << bitsb.to_string() << "\n\n\n"
            << bitsc.to_string() << "\n";
}
