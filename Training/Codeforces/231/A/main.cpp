#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n;
	cin >> n;
	ll done = 0;
	for(ll i = 0; i <n ;++i){
		ll a,b,c;
		cin >> a >> b >> c;
		if(a+b+c > 1){
			done++;
		}
	}

	cout << done << "\n";
}
