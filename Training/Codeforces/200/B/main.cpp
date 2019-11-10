#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  scanf("%lld", &n);
  ll sum = 0;
  for (ll i = 0; i < n; ++i) {
    ll x;
    scanf("%lld", &x);
    sum += x;
  }

  printf("%.12f\n", ((double)sum / (double)(n * 100))*100);
}
