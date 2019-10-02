#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet tests;
	cin >> tests;
	while(tests--){
		sizet days;
		cin >> days;
		vector<bool> forecast(days+1);
		sizet parties;
		cin >> parties;
		sizet cnt = 0;
		while(parties--){
			sizet average;
			cin >> average;
			for(sizet i = average; i < days+1; i+=average){
				forecast[i] = 1;
			}
		}
		for(sizet i = 1; i <= days; ++i){
			if( (i % 7 != 6) && (i % 7 != 0) && forecast[i])
				cnt++;
		}
		cout << cnt << "\n";

	}
}
