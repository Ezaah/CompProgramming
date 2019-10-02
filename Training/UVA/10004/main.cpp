#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet n;
	while(cin >> n){
		if(n == 0){
			break;
		}
		vector<vector<sizet>> adj_list(n);
		sizet edges;
		cin >> edges;
		for(sizet i = 0; i < edges; ++i){
			sizet u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		vector<sizet> colors(n, -1);
		vector<bool> visited(n);
		queue<sizet> que;
		que.push(0);
		colors[0] = 0;
		bool state = true;
		while(!que.empty()){
			sizet u = que.front();
			que.pop();
	//		cout << "visiting " << u << endl;
			if(visited[u]){
				continue;
			}
			visited[u] = 1;
			for(auto& v : adj_list[u]){
	//			cout << "comparing " << u << " " << v << endl;
	//			cout << "colors: " << colors[u] << " " << colors[v] << endl;
				if(colors[v] == colors[u]){
					state = false;
				}else{
					que.push(v);
					colors[v] = 1 - colors[u];
				}
			}
		}
		if(state){
			cout << "BICOLORABLE.\n";
		}else{
			cout << "NOT BICOLORABLE.\n";
		}
	}

}
