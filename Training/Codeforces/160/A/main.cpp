#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> coins(n);
	int sum = 0;
	for(int i = 0; i <n; ++i){
		cin >> coins[i];
		sum += coins[i];
	}

	sort(coins.rbegin(), coins.rend());

	int k = 0;
	int taken = 0;
	while(taken <= sum && k < n){
		sum -= coins[k];
		taken += coins[k];
		k++;
	}

	cout << k << "\n";


}
