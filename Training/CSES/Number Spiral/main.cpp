#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet tests;
	cin >> tests;
	while(tests--){
		sizet i,j;
		cin >> i >> j;
		if(i == j){
			cout << i*i - (i - 1) << "\n";
		}else if(i > j){
			if(i % 2){
				cout << i*(i-1) - (i - 1 - j) << "\n";
			}else{
				cout << i*i - (j - 1) << "\n";
			}
		}else{
			if(j % 2){
				cout << j*j - (i -1) << "\n";
			}else{
				cout << j*(j-1) - (j - 1 - i) << "\n";
			}
		}
	
	}
}
