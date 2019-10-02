#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet n;
	cin >> n;
	vector<sizet> ans(n);
	for(sizet i = 0; i < n; i++){
		string word;
		cin >> word;

		if(word.size() == 5){
			ans[i] = 3;
		}else{
			sizet one = 0;
			sizet two = 0;
			if(word[0] == 'o'){
				one++;
			}else if(word[0] == 't'){
				two++;
			}

			if(word[1] == 'n'){
				one++;
			}else if(word[1] == 'w'){
				two++;
			}

			if(word[2] == 'e'){
				one++;
			}else if(word[2] == 'o'){
				two++;
			}

			if(one > two){
				ans[i] = 1;
			}else{
				ans[i] = 2;
			}
		}

	}

	for(sizet i = 0; i < n; i++){
		cout << ans[i] << "\n";
	}


}
