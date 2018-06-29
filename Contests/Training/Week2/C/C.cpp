#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;


int main(){
	sizet days;
	cin >> days;
	vector<sizet> results(3);
	for(sizet i = 0; i < days; i++){
		sizet comps;
		cin >> comps;
		sizet won = 0;
		sizet half = comps/2;
		for(sizet  j = 0; j < comps; j++){
			sizet result;
			cin >> result;
			won+=result;
		}
		if(won > half){
			results[1]++;
		}else if(won < half){
			results[0]++;
		}else{
			results[2]++;
		}
	}
	cout << results[0] << " " << results[1] << " " << results[2] << "\n";
}
