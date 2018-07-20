#include <bits/stdc++.h>
using namespace std;

int converter(char a){
  return a - '0';
}

int main(){
  string input;
  cin >> input;
  size_t impares = 0;
  bool par = true;
  if(converter(input[input.size() - 1]) % 2 != 0){
    par = false;
  }

  for(auto chr : input){
    if(converter(chr) % 2 != 0){
      impares++;
    }
  }
  if(par && (impares % 2 == 0)){
    cout << "superpar\n";
  }else{
    cout << "no\n";
  }
}
