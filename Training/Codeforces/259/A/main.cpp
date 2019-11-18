#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	bool possible = 1;
	for(ll k = 0; k <8; ++k){
		string board;
		cin >> board;
		board += board.front();
		for(ll i =0; i +1 < 8; ++i){
			if(board[i] == board[i+1]){
				possible = 0;
			}
		}
	}

	if(possible){
		cout<< "YES\n";
	}else{
		cout << "NO\n";
	}


}
