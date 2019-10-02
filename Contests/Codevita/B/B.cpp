#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n;
	cin >> n;
	sizet bin_size;
	cin >> bin_size;
	vector<sizet> sizes(n);
	sizet total = 0;
	for(sizet i = 0; i < n; ++i){
		sizet aux, value;
		cin >> aux >> value;
		sizes[i] = value;
		total +=  value;
	}

	function<sizet()> cont;
	cont = [&](){
		unordered_map<sizet, sizet> old;
		sizet ans = 0;
		sizet sum = 0;
		for(sizet i = 0; i < n; ++i){
			sum += sizes[i];
		//	cout << sum << " " << ans << endl;
			if(sum == bin_size){
				ans++;
			}else if(old.find(sum - bin_size) != old.end()){
			//	cout << sum - bin_size << endl;
				ans += old[sum - bin_size];
			}else{
				old[sum]++;
			}
		//	cout << sum << " " << ans << endl;
		}
		if(ans*bin_size < total){
			ans++;
		}
		return ans;
	};
	cout << cont() << "\n";


}
