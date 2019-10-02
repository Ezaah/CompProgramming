#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

sizet f(sizet k, sizet m, sizet s){
	if(m == 0){
		return s;
	}
	if(s == 1){	
		sizet sum = 0;
		for(sizet i = 0; i < k; ++i){
			sum += f(i, m-1, 0);
		}

		sum+= (26 - k)*pow(k, m-1);
		cout << k << " " << m << " " << s << " " << sum << endl;
		return sum;
	}else{
		sizet sum = 0;
		for(sizet i = 0; i < k; ++i){
			sum += f(i, m-1, 1);
		}
		cout << k << " " << m << " " << s << " " << sum << endl;
		return sum;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet sum = 0;
	for(sizet i = 1; i <= 7; ++i){
		sum += f(6, i, 0);
	}
	cout << sum << endl;

}
