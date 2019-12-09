#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print_monsters(vector<pair<ll,ll>> a){
	for(auto x : a){
		cout << "{" << x.first << "," << x.second << "} ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	ll s, n;
	cin >> s >> n;

	vector<pair<ll,ll>> monsters(n);
	for(ll i = 0; i < n; ++i){
		cin >> monsters[i].first >> monsters[i].second;
	}
	//print_monsters(monsters);
	sort(monsters.begin(), monsters.end(), [](pair<ll,ll> x, pair<ll,ll> y){
			if(x.first == y.first){
				return x.second > y.second;
				}
				return x.first < y.first;
			});
	//print_monsters(monsters);
	ll k = 0;
	ll impossible = 0;
	while(k < n){
	//	cout << "Fighting monster " << k << " with life " <<monsters[k].first << " and reward " << monsters[k].second << " ( s = " << s << ")" << endl;
		if(monsters[k].first >= s){
			impossible=1;
			break;
		}

		s+= monsters[k].second;
		k++;
	}

	if(impossible){
		cout << "NO\n";
	}else{
		cout << "YES\n";
	}


}
