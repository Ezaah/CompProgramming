#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet cases;
	cin >> cases;
	while(cases--){
		sizet farmers;
		cin >> farmers;
		sizet sum = 0;
		while(farmers--){
			sizet land, animals, friendly;
			cin >> land >> animals >> friendly;
			sum += land*friendly;
		}
		cout << sum << "\n";
	}


}
