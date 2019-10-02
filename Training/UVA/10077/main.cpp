#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;
typedef pair<sizet,sizet> par;

par combiner(par& a, par& b){
	return {a.first + b.first, a.second + b.second};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n, m;
	while(cin >> n >> m){
		if(n==1 && m == 1){
			break;
		}
		vector<par> triplet = { {0,1}, {1,1}, {1,0}};
		double objective = (double) n/m;
		string ans = "";
		while((double) triplet[1].first/triplet[1].second != objective){
			if((double) triplet[1].first/triplet[1].second > objective){
				ans +="L";
				triplet = {triplet[0], combiner(triplet[0], triplet[1]), triplet[1]};
			}else{
				ans+="R";
				triplet = {triplet[1], combiner(triplet[1], triplet[2]), triplet[2]};
			}
		}
		cout << ans << "\n";
	}

}
