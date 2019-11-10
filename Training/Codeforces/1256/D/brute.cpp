#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;
void print_bits(string a) { cout << a << endl; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet tests;
  cin >> tests;
  while (tests--) {
    sizet n, k;
    cin >> n >> k;
    string bitstr;
    cin >> bitstr;

    while (k > 0) {
      sizet pos_0 = 0;
      bool sorted = 0;
      for (sizet i = 0; i < n - 1; ++i) {
        if (bitstr[i] == '1' && bitstr[i + 1] == '0') {
          pos_0 = i + 1;
          break;
        }

        if (i == n - 2) {
          sorted = 1;
        }
      }
      if (sorted) {
        break;
      }

      sizet pos_next0 = 0;
      for (sizet i = pos_0 - 1; i > -1; --i) {
        if (bitstr[i] == '0') {
          pos_next0 = i;
          break;
        }
      }

      if (pos_0 - pos_next0 > k) {
        pos_next0 = pos_0 - k;
      }
      //   cout << bitstr.substr(0, pos_next0) << " "
      //        << bitstr.substr(pos_next0, pos_0 - pos_next0) << " "
      //        << bitstr[pos_0] << " " << bitstr.substr(pos_0 + 1) << endl;
      bitstr = bitstr.substr(0, pos_next0) + bitstr[pos_0] +
               bitstr.substr(pos_next0, pos_0 - pos_next0) +
               bitstr.substr(pos_0 + 1);
      k -= (pos_0 - pos_next0);
    }

    cout << bitstr << "\n";
  }
}
