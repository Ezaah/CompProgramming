#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet c_a, b_a, p_a, c_r, b_r, p_r;
	while(cin >> c_a >> b_a >> p_a >> c_r >> b_r >> p_r){
		sizet sum = 0;
		if(c_a - c_r < 0){
			sum += c_r - c_a;
		}
		if(b_a - b_r < 0){
			sum+= b_r - b_a;
		}
		if(p_a - p_r < 0){
			sum += p_r - p_a;
		}
		cout << sum << "\n";
	}

}
