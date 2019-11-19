#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }

  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  double angle;
  cin >> angle;
  ll ang = angle * 100 + 0.5;
  

  cout << 36000/gcd(ang,36000) << "\n";

  
}
