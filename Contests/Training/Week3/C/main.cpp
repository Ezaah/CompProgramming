#include <bits/stdc++.h>
using namespace std;
typedef long long int sizet;


int main(){
  sizet n;
  cin >> n;
  sizet benja = 0;
  sizet empate = 0;
  sizet martina = 0;
  for(sizet i = 0; i < n; i++ ){
    sizet m;
    cin >> m;
    sizet sum = 0;
    for(sizet j = 0; j < m; j++){
      sizet aux;
      cin >> aux;
      sum += aux;
    }
    if(sum > m/2){
      benja++;
    }else if(sum == (int)m/2){
      empate++;
    }else{
      martina++;
    }
  }
  cout << martina << " " << benja << " " << empate << "\n";
}
