#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll tests;
	cin >> tests;
	while(tests--){
		ll n;
		cin >> n;
		vector<ll> planks(n);
		for(ll i = 0; i < n; ++i){
			cin >> planks[i];
		}

		sort(planks.begin(), planks.end());
		ll max_element = planks.back();

		while(max_element > 0){
			ll elems = count_if(planks.begin(), planks.end(), [&](ll i){ return i >= max_element;});
			if(elems >= max_element){
				break;
			}
			max_element--;
		}

		cout << max_element << "\n";
	}	
}
