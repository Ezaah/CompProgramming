#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

sizet gcd(sizet a, sizet b){
	if(b == 0){
		return a;
	}
	return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet tests;
  scanf("%lld", &tests);
  while (tests--) {
    sizet a, b;
    scanf("%lld%lld", &a, &b);
    vector<int> colors(50);
    colors[0] = 1;
    for (sizet i = 1; i < 50; ++i) {
      if (i - a > -1) {
		  if(colors[i-a] == 1){
        	colors[i] = colors[i - a];
        	continue;
		  }
      }

      if (i - b > -1) {
		  if(colors[i-b] == 1){
        	colors[i] = colors[i - b];
		  }
      }
    }
    printf("(%lld,%lld) : ", a, b);
    for (auto x : colors) {
      printf("%d ", x);
    }
    printf("\n");
  }
}
