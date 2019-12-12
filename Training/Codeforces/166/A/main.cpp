#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  cout << fixed;

  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> codes(n);
  map<pair<int,int>, int> eq;
  for(int i = 0; i < n; ++i){
    cin >> codes[i].first >> codes[i].second;
    if(eq.count(codes[i])){
      eq[codes[i]]++;
    }else{
      eq[codes[i]] = 1;
    }
  }

  sort(codes.begin(), codes.end(), [](pair<int,int> a, pair<int,int> b){ if(a.first == b.first){ return a.second < b.second; } return a.first > b.first;});
  cout << eq[codes[k-1]] << "\n";

#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

}
