#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string code;
	cin >> code;


	for(char elem :  code){
		if(elem == 'H' || elem == 'Q' || elem=='9'){
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
}
