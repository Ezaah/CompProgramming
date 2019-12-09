#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	while(n--){
		ll c, s;
		cin >> c >> s;

		vector<ll> heaters(c);
		for(ll i = 0; i < s; ++i){
			heaters[i % c]++;
		}

		ll cost = 0;
		for(ll i = 0; i < c; ++i){
			cost += heaters[i]*heaters[i];
		}

		cout << cost << "\n";
	}
}
