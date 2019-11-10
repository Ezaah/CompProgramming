#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string a,b;
	cin >> a >> b;
	transform(a.begin(), a.end(), a.begin(), [](char x){ return tolower(x);});
	transform(b.begin(), b.end(), b.begin(), [](char x){ return tolower(x);});
	if(a == b){
		cout << "0\n";
	}else if(a < b){
		cout << "-1\n";
	}else{
		cout << "1\n";
	}
}
