#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet width;
	while(cin >> width){
		sizet n;
		cin >> n;
		sizet area = 0;
		for(sizet i = 0; i < n; ++i){
			sizet w, h;
			cin >> w >> h;
			area += w*h;
		}
		cout << area/width << "\n";
	}

}
