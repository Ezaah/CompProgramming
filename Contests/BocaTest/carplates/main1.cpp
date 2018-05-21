#include <bits/stdc++.h>
using namespace std;

int main() {
  string a = "BBBBB23";
  string b = "ABC1235";
  int c = 77;
  vector<int> aint(7);
  if (isalpha(b[3]) == isalpha(b[4])) {
    for (int i = 0; i < 7; ++i) {
      if (i < 5) {
        aint[i] = int(a[i]) - 'A';
      } else {
        aint[i] = int(a[i]) - '0';
      }

      cout << aint[i] << " ";
    }
  } else if (!isalpha(b[3]) == !isalpha(b[4])) {
    for (int i = 0; i < 7; ++i) {
      if (i < 3) {
        aint[i] = int(a[i]) - 'A';
      } else {
        aint[i] = int(a[i]) - '0';
      }

      cout << aint[i] << " ";
    }
  } else {
    cout << "N\n";
    continue;
  }
  cout << "\n";
  for (int i = 6; i > -1; i--) {
    int suma = aint[i] + c;
    if (isalpha(a[i])) {
      int mod = suma % 26;
      if (mod == 0 || mod == 2 || mod == 8 || mod == 12 || mod == 14) {
        mod++;
      }
      aint[i] = mod;
      c = suma / 26;
    } else {
      aint[i] = suma % 10;
      c = suma / 10;
    }
  }
  for (int i = 0; i < 7; i++) {
    cout << aint[i] << " ";
  }
  cout << "\n";
  string outa;
  for (int i = 0; i < 7; ++i) {
    if (i < 5) {
      outa.push_back(char(aint[i] + 'A'));
    } else {
      outa.push_back(char(aint[i] + '0'));
    }
  }
  for (char car : outa) {
    cout << car << " ";
  }
  // cout << (a < b) << endl;
}
