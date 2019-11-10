#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
  puts("1");
  int a = rand(2, 10);
  int b = rand(2, 10);
  int n = rand(2, 10);
  int s = rand(2, 10);
  printf("%d %d %d %d\n", a, b, n, s);
}
