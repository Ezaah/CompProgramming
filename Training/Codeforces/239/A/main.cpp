#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll y,k,n;
	cin >> y >> k >> n;

	ll rem = y % k;
	vector<ll> values;
	for(int i = k - rem; i <= n -y; i+=k){
			values.push_back(i);
	}

	if(values.empty()){
		cout << "-1\n";
	}else{
		for(auto x : values){
			cout << x << " ";
		}
		cout << "\n";
	}
}
