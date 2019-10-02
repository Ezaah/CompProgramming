#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet n, m, s;
	cin >> n >> m >> s;
	sizet i = 0;
	sizet j = n-1;
	sizet sum = 0;
	sizet from = 0;
	sizet mid = ceil((double)(j + i)/2);
	while(j >=  i){
		//cout << i << " "<< mid << " "<< j  << " from: " << from<<  " adding: " << abs(mid - from)*m + s<<endl;
		sum += abs(mid- from)*m + s;
	//	mid += i;
		if(abs(mid - from) == 1){
			break;
		}
		from = mid;
		if(mid - i  <= j - mid){
			i = mid + 1;
			mid = ceil((double)(j + mid)/2);
		}else{
			j = mid - 1;
			mid = ceil((double)(i + mid)/2);
		}
	}
	cout << sum << endl;
	

}
