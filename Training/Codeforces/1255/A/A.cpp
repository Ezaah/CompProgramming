#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tests;
	cin >> tests;
	while(tests--){
		ll a,b;
		cin >> a >> b;

		ll cnt =0;

		if(a < b){
			ll delta  = b -a;
			cnt += delta/5;
			delta = delta % 5;

			cnt += delta/2;
			delta = delta % 2;
			cnt += delta;
			delta = 0;

		}else{
			ll delta  = a - b;
			cnt += delta/5;
			delta = delta % 5;

			cnt += delta/2;
			delta = delta % 2;
			cnt += delta;
			delta = 0;
		}
		// while(a != b){
		// 	if(a > b){
		// 		if(a - 5 >= b && a > 4){
		// 			cnt++;
		// 			a-=5;
		// 		}else if(a - 2 >= b && a > 1){
		// 			cnt++;
		// 			a-=2;
		// 		}else if(a - 1 >= b && a > 0){
		// 			cnt++;
		// 			a--;
		// 		}
		// 	}else{
		// 		if(a + 5 <= b){
		// 			cnt++;
		// 			a+=5;
		// 		}else if(a + 2 <= b){
		// 			a+=2;
		// 			cnt++;
		// 		}else if( a+1 <= b){
		// 			a++;
		// 			cnt++;
		// 		}
		// 	}
		// }

		cout << cnt << "\n";

	}

}
