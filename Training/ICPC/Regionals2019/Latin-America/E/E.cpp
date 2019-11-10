#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	string cake;
	cin >> cake;

	ll max_slices;
	cin >> max_slices;

	ll e_fruits = count_if(cake.begin(), cake.end(), [](char a){ return a == 'E';});
	ll sum = 0;
	for(ll i = 1; i <= max_slices; ++i){
		sum += min((ll)cake.size(), i*e_fruits);
	}
	cout << sum << "\n";
}
