#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll tests;
  cin >> tests;
  while (tests--) {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool possible = 0;
    for(ll i = 0; i < n; ++i){
      for(ll j = 0 ; j < n; ++j){
        swap(a[i], b[j]);
        if(a == b){
          possible = 1;
          break;
        }
        swap(a[i], b[j]);
      }
      if(possible){
        break;
      }
    }
    if(possible){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }
}
