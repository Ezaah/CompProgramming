#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet tests;
	cin >> tests;
	while(tests--){
		sizet relatives;
		cin >> relatives;
		vector<sizet> streets(relatives);
		for(sizet i = 0; i < relatives; ++i){
			cin >> streets[i];
		}
		sort(streets.begin(), streets.end());
		sizet mid = relatives/2;
	//	cout << mid << " " << streets[0] << " " << streets[relatives-1] << endl;
		sizet sum = 0;
		for(sizet i = 0; i < relatives; ++i){
			sum += abs(streets[i] -streets[mid]);
		}
		cout << sum << "\n";

	}

}
