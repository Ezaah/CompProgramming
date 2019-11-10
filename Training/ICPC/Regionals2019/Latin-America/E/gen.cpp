#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
  int n = rand(3, 6);
  for (int i = 0; i < n; ++i) {
    if (rand(0, 10) > 5) {
      cout << "E";
    } else {
      cout << "P";
    }
  }
  cout << endl;

  cout << rand(1, n - 1) << endl;
}
