#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet n;
	cin >> n;
	vector<sizet> bits(n, 1);
	sizet last_correct = 0;
	for(sizet i = 0; i < n; ++i){
		cout << "Q ";
		for(sizet j = 0; j < n; j++){
			cout << bits[j];
			if(j < n-1)
				cout << " ";
		}
		cout << endl;
		sizet correct;
		cin >> correct;
		if(correct == n){
			break;
		}
		if(correct < last_correct){
			bits[i-1] = 1 - bits[i-1];
		}else{
			last_correct = correct;
		}
		bits[i] = 1 - bits[i];
	}
	cout << "A ";
	for(sizet j = 0; j < n; j++){
		cout << bits[j];
		if(j<n-1)
			cout << " ";
	}
	cout << endl;


}
