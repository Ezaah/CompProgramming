#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

sizet gcd(sizet a, sizet b){
	if(b == 0){
		return a;
	}
	return gcd(b, a % b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet tests;
	scanf("%lld", &tests);
	while(tests--){
		sizet a,b;
		scanf("%lld%lld", &a,&b);
		if(gcd(a,b) == 1){
			puts("Finite");
		}else{
			puts("Infinite");
		}
	}

}
