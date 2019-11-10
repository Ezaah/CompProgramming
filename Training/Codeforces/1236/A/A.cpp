#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet tests;
	scanf("%lld", &tests);
	while(tests--){
		sizet a,b,c;
		scanf("%lld%lld%lld", &a,&b,&c);

		sizet movesB = min(b, c/2);
		b -= movesB;
		c -= 2*movesB;
		sizet movesA = min(a,b/2);
		printf("%lld\n", 3*movesA + 3*movesB);
		
	}
}
