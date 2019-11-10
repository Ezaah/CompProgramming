#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  srand(stoi(argv[1]));
  for (sizet i = 0; i < 1e5; ++i) {
    sizet val = rand();
    if (val % 3 == 0) {
      printf("a");
    } else if (val % 3 == 1) {
      printf("u");
    } else {
      printf("n");
    }
  }
}
