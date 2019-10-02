#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;
sizet mod_sum(sizet a, sizet b, sizet mod){
	if(a < m - b)
		return a + b;
	return a - ( m  - b);
}
sizet mod_mul(sizet a, sizet b, sizet mod){
	sizet res = 0;
	while(b > 0){
		if(b%2)
			res = mod_add(res, a, mod);
		a = mod_add(a,a,mod);
		b/=2;
	}
	return res;
}
struct edge{
	sizet a;
	sizet b;
	sizet rate;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet n;
	cin >> n;
	unordered_map<string, sizet> indexes;
	vector<edge> exchanges;
	sizet vertices = 0;
	for(sizet i = 0; i < n; ++i){
		string a, b;
		sizet rate;
		cin >> a >> b >> rate;
		sizet i ,j;
		if(indexes.find(a) == indexes.end()){
			i = vertices;
			indexes[a] = vertices;
			vertices++;
		}else{
			i = indexes[a];
		}

		if(indexes.find(b) == indexes.end()){
			j = vertices;
			indexes[b] = vertices;
			vertices++;
		}else{
			j = indexes[b];
		}
		exchanges.push_back({i, j,rate});
	}


}
