#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b;
	while(cin >> a >> b){
		if(a == "0" && b == "0"){
			break;
		}
		if(a.size() > b.size()){
	//		cout << a.size() - b.size() << endl;
			sizet dif = a.size() - b.size();
			for(sizet i = 0; i < dif; ++i){
	//			cout << i << endl;
				b = '0' + b;
			}
		}else if(a.size() < b.size()){
			sizet dif = b.size() - a.size();
	//		cout << b.size() - a.size() << endl;
			for(sizet i = 0; i < dif; ++i){
				a = '0' + a;
			}
		}
	//	cout << a << " " << b << endl;
		sizet cnt = 0;
		sizet carry = 0;
		for(sizet i = a.size()- 1; i >= 0; --i){
			sizet digit_a = a[i] - '0';
			sizet digit_b = b[i] - '0';
			if(digit_a + digit_b + carry > 9){
				cnt++;
				carry = 1;
			}else{
				carry = 0;
			}
		}
		if(cnt == 0){
			cout << "No carry operation.\n";
		}else if(cnt == 1){
			cout << "1 carry operation.\n";
		}else{
			cout << cnt << " carry operations.\n";
		}
	}


}
