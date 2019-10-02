#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

void debug(vector<sizet>& v){
	for(auto& elem : v){
		cout << elem << " ";
	}
	cout << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet t;
	cin >> t;
	while(t--){
		sizet s, e;
		cin >> s >> e;
		if(e == 0){
			cout << "!OK\n";
			continue;
		}
		vector<sizet> numbers(e);
		map<sizet, vector<sizet>> indexes;
		vector<pair<sizet,sizet>> answers;
		vector<sizet> original;
		for(sizet i = 0; i < e; ++i){
			cin >> numbers[i];
			indexes[numbers[i]].push_back(i);
			original.push_back(numbers[i]);
		}

		sort(numbers.begin(), numbers.end());
		function<sizet(sizet, sizet, sizet)> exist;
		exist = [&](sizet i, sizet j, sizet x){
//			cout << i << " " << j << endl;
			if(i > j){
				return sizet{-1};
			}
			sizet mid = i + (j - i)/2;
			if(numbers[mid] == x){
				return mid;
			}else if(numbers[mid] > x){
				return exist(i, mid-1, x);
			}else{
				return exist(mid+1, j, x);
			}
		};
		bool flag = false;
		sizet a, b;
	//	debug(numbers);
		for(sizet i = 0; i < e-1; ++i){
//			cout << numbers[i] << " <- a | looking for -> " << s - numbers[i] << " " << endl;
			sizet mid = exist(i+1, e, s - numbers[i]);
			if(mid != -1){
				flag = true;
				for(sizet k = 0; k < indexes[numbers[i]].size(); ++k){
					for(sizet j = 0; j < indexes[numbers[mid]].size(); ++j){
						sizet alfa = indexes[numbers[i]][k];
						sizet beta = indexes[numbers[mid]][j];
						if(alfa > beta){
							swap(alfa,beta);
						}
						if(alfa!= beta)
							answers.push_back({alfa,beta});
					}
				}
			}
		}
		sort(answers.begin(), answers.end(), [](const pair<sizet,sizet> &left, const pair<sizet,sizet>& right){
				return left.second < right.second;
				}
		    );
/*		for(auto& elem : answers){
			cout << "("<<elem.first<< ","<<elem.second<<"),";
		}
		cout << endl; */
		if(flag){
			sizet a = original[answers[0].first];
			sizet b = original[answers[0].second];
			if(a > b){
				swap(a,b);
			}
			cout << a << " "<<b << "\n";
		}else{
			cout << "!OK\n";
		}
	}

}
