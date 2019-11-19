#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string a,b;
	cin >> a >> b;

	reverse(b.begin(), b.end());

	(a == b)? cout << "YES\n" : cout << "NO\n";

}
