#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet tests;
	cin >> tests;
	for(sizet i = 0; i < tests; ++i){
		sizet walls;
		cin >> walls;
		sizet actual;
		cin >> actual;
		sizet high = 0;
		sizet low = 0;
		for(sizet j = 1; j < walls; j++){
			sizet wall;
			cin >> wall;
			if(actual > wall){
				low++;
			}else if(actual < wall){
				high++;
			}
			actual = wall;
		}
		printf("Case %d: %d %d\n", i +1, high, low);
	}

}
