#include <bits/stdc++.h>
typedef long long sizet;

std::pair<sizet, sizet> combiner(std::pair <sizet, sizet>& a, std::pair <sizet, sizet>& b){
	return {a.first + b.first, a.second + b.second};
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sizet n;
	std::cin >> n;
	std::vector< std::pair<sizet, sizet> > init = { {0, 1}, { 1, 1}, {1, 0}};
	std::string input;
	std::vector< std::pair<sizet, sizet> > iterator;
	for(sizet i = 0;i < n; i++){
		std::cin >> input;
		iterator = init;
		for(sizet j = 0; j < input.size(); j++){
			if(input[j] == 'R'){
				iterator = { iterator[1], combiner(iterator[1], iterator[2]), iterator[2]};
			}else if(input[j] == 'L'){
				iterator = { iterator[0] , combiner(iterator[0], iterator[1]), iterator[1]};
			}
		}
		std::cout << iterator[1].first << "/" << iterator[1].second << "\n";
	}
}
