#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll a,b,c;
	cin >> a >> b >> c;

	ll alpha = sqrt((b*c)/a);
	ll beta = b/alpha;
	ll gamma = c/alpha;

	cout << 4*alpha + 4*beta + 4*gamma << "\n";



}
