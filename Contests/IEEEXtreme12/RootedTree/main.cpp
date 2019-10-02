#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;
void add_spaces(sizet n){
	while(n--){
		cout << " ";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string inorder, preorder;
	while(cin >> inorder >> preorder){
		unordered_map<char, sizet> indexes;
		for(sizet i = 0; i < inorder.size(); ++i){
			indexes[inorder[i]] = i;
		}
		
		map<sizet, vector<char>> levels;
		sizet max_depth = -1;
		function<void(sizet, sizet, sizet, sizet)> builder;
		builder = [&](sizet pre_i, sizet ind_i, sizet ind_j, sizet depth){
			if(ind_i >= ind_j){
				levels[depth].push_back(' ');
				return;
			}
			if(depth > max_depth){
				max_depth = depth;;
			}
			char root = preorder[pre_i];
			sizet pos = indexes[root];
	//		cout << root << " " << pos << " " << depth << " " << pre_i << " " << ind_i << " " << ind_j << endl;
			levels[depth].push_back(root);
			builder(pre_i + 1, ind_i, pos, depth +1);
			builder(pre_i + 1 + (pos - ind_i), pos + 1, ind_j, depth + 1);

		};

		builder(0, 0, inorder.size(),  0);
//		cout << max_depth << endl;

		for(auto &vc : levels){
//			cout << vc.second.size() << endl;
			if(vc.first > max_depth)
				continue;
			for(auto& elem : vc.second){
				if(vc.first == 0){
					add_spaces(max_depth - vc.first + 1);
				}else{
					add_spaces(max_depth - vc.first);
				}
				cout << elem;
				add_spaces(max_depth - vc.first+1);

			}
			cout << "\n";
		}
	}


}
