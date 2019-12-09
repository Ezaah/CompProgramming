#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	int n;
	cin >> n;

	vector<pair<ll,ll>> segments(n);
	ll maxi = 0;
	ll mini = 1e9;
	for(int i = 0; i < n; ++i){
		cin >> segments[i].first >> segments[i].second;
		mini = min(mini, segments[i].first);
		maxi = max(maxi, segments[i].second);
	}

	int pos = -1;
	for(int i = 0; i < n; ++i){
		if(segments[i].first == mini && segments[i].second == maxi){
			pos = i+1;
			break;
		}
	}

	cout << pos << "\n";
}
