#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet tests;
	cin >> tests;
	while(tests--){
		sizet k, w;
		cin >> k >> w;
		string messages;
		cin >> messages;
		for(sizet i = 1; i < w; ++i){
			string word;
			cin>>word;
			bool whole = true;
			for(sizet j = 0; j < k; ++j){
				if(messages.substr(messages.size()-k+j) == word.substr(0,k-j)){
					messages += word.substr(k-j, j);
					whole = false;
					break;
				}
			}
			if(whole){
				messages += word;
			}
		}
		
		cout << messages.size() << "\n";	

	}
}
