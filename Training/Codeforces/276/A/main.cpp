#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n, k;
	cin >> n >> k;
	ll joy = -1e10;
	for(ll i = 0; i < n; ++i){
		ll f,t;
		cin >> f >> t;
		if(t > k){
			f -= t - k;
		}
		joy = max(joy, f);
	}
	cout << joy << "\n";
}
