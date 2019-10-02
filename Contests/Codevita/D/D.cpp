#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

sizet strip_digit(sizet value, sizet pos){
	string value_str = to_string(value);
	value_str.erase(value_str.begin() + pos);
	return stoi(value_str);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet tests;
	cin >> tests;
	while(tests--){
		sizet n;
		cin >> n;
		sizet total;
		cin >> total;
		vector<sizet> values(n);
		sizet sum = 0;
		for(sizet i = 0; i < n; ++i){
			cin >> values[i];
			sum +=values[i];
		}
		for(sizet i = 0; i < n; ++i){
			bool found = 0;
			for(size_t k = 0; k < to_string(values[i]).size(); ++k){
					sizet posibility = strip_digit(values[i], k);
					if(sum - values[i] + posibility == total){
						cout << posibility << "\n";
						found = 1;
						break;
					}
			}
			if(found){
				break;
			}
		}
	}

}
