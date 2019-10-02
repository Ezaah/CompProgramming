#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet n;
	while(cin >> n){
		if(n < 0){
			break;
		}

		cout << (n*n + n)/2 + 1 << "\n";
	}

}
