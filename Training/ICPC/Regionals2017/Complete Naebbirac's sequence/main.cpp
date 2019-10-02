#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet k, n;
	while(cin >> k>> n){
		sizet times = (n+1)/k;

		unordered_map<sizet, sizet> freq;
		for(sizet i = 0; i < n; ++i){
			sizet a;
			cin >> a;
			if(freq.find(a) != freq.end()){
				freq[a]++;
			}else{
				freq[a] = 1;
			}
		}
		sizet on_time = 0;
		sizet below = 0;
		sizet over = 0;
//		cout << times << endl;
		for(auto& par : freq){
			if(par.second < times){
				below++;
			}else if(par.second == times){
				on_time++;
			}else{
				over++;
			}
		}
//		cout << below << " " << on_time << " " << over << endl;
		if(over == 1 && below == 1){
			sizet remove, add;
			for(auto& par : freq){
				if(par.second > times){
					remove = par.first;
				}else if(par.second < times){
					add = par.first;
				}
			}
			cout << "-" << remove << " +" << add << "\n";
		}else if(over == 1 && below == 0){
			for(auto& par : freq){
				if(par.second > times){
					cout << "-" << par.first << "\n";
					break;
				}
			}
		}else if(over == 0 && below == 1){
			for(auto& par : freq){
				if(par.second < times){
					cout << "+" << par.first << "\n";
					break;
				}
			}
		}else{
			cout << "*\n";
		}
	}

}
