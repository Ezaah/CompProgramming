#include <bits/stdc++.h>
typedef long long sizet;


bool check(std::vector<sizet>& values){
	std::vector<std::pair<sizet,sizet>> edges = {{1,2}, {1,3}, {1,5}, {2,3}, {2,5},{3,4}, {3,5}, {4,5}};
	std::vector<bool> result(9, false);
	for(sizet i = 0; i < 8; i++){
		sizet a = values[i];
		sizet b = values[i+1];
		if(a > b){
			std::swap(a,b);
		}
		bool flag = false;
		for(sizet j = 0; j < edges.size(); j++){
			if(std::make_pair(a,b) == edges[j] && !result[j]){
				result[j] = 1;
				flag = 1;
				break;
			}
		}
		if(!flag){
			return false;
		}
	}
	return true;
}

int main(){
	std::vector<sizet> values(9,1);
	values[0] = 1;
	values[8] = 2;
	for(values[1] = 1; values[1] < 6; values[1]++){
		for(values[2] = 1; values[2] < 6; values[2]++){
			for(values[3] = 1; values[3] < 6; values[3]++){
				for(values[4] = 1; values[4] < 6; values[4]++){
					for(values[5] = 1; values[5] < 6; values[5]++){
						for(values[6] = 1; values[6] < 6; values[6]++){
							for(values[7] = 1; values[7] < 6; values[7]++){
								if(check(values)){
									for(sizet i = 0; i < 9; i++){
										std::cout << values[i];
									}
									std::cout << "\n";
								}
							}
						}
					}
				}
			}
		}
	}

}
