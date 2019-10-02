#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n;
	cin >> n;
	sizet d;
	cin >> d;
	vector<double> lamps(n);
	for(sizet i = 0; i < n; ++i){
		double coverage;
		cin >> coverage;
		lamps[i] = (coverage/2)/d;
	}
	vector<vector<double>> who(n, vector<double>(n-1));

	for(sizet i = 0; i < n; ++i){
		for(sizet j = 0; j < n; ++j){

			sizet dist = abs(j - i);
			/*if(i == j){
				dist++;
			}*/
			cout << i<< " " << j << " | " << dist + 1<< " " << lamps[i]<< endl;
			/*
			if(lamps[j] >= dist + 1){
				who[j][i] = 1;
			}else if(lamps[j] > dist-1){
				who[j][i] = lamps[j] - dist-1;
			}
			*/
		}
	}

	for(sizet i = 0; i < n; ++i){
		cout << "for lamp " << i << endl;
		cout << "| ";
		for(auto& par : who[i]){
			cout << par<< " | ";
		}
		cout <<endl;
	}



}
