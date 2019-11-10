#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string word;
	cin >> word;

	ll upper = count_if(word.begin(), word.end(), [](char x){ return isupper(x);});
	ll lower = count_if(word.begin(), word.end(), [](char x){ return islower(x);});

	if(upper > lower){
		transform(word.begin(), word.end(), word.begin(), [](char x){ return toupper(x);});
	}else{
		transform(word.begin(), word.end(), word.begin(), [](char x){ return tolower(x);});
	}

	cout << word << "\n";
}
