#include <bits/stdc++.h>
using namespace std;

int prima(size_t n){
  return log10(n) + 1;
}
int main(){
  size_t x, y, z;
  cin >> x >> y >> z;
  size_t n0, n1;
  n0 = ceil((float)x/(z - y));
  n1 = ceil((float) x/(z - y - (2*prima(n0) + 1)));
  cout << n1;

}
