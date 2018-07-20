#include <bits/stdc++.h>
typedef long long sizet;

class Graph {
	std::vector< std::vector<sizet> > adj_list;

	public:

	Graph (sizet num_vertices) : adj_list(num_vertices) {}

	void add_edge (sizet u, sizet v){
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	std::vector<sizet> out_edges(sizet u){
		return adj_list[u];
	}

};


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sizet n, m, i ,j;
	std::vector<sizet> answers;
	while(true){
		std::cin >> n >> m;
//		std::cout << n << " " << m << std::endl;
		if(n == 0 && m == 0){
			break;
		}
		Graph graph(n);
		for(sizet k = 0; k < m; k++){
			std::cin >> i >> j;
//			std::cout << i << " " << j << std::endl;
			i--;
			j--;
			graph.add_edge(i,j);
		}
		std::vector<bool> visited(n);

		std::function<void(sizet, sizet)> dfs;
		dfs = [&](sizet vertice, sizet parent){
			visited[vertice] = 1;

			for(auto v :  graph.out_edges(vertice)){
				if(v == parent || visited[v]){
					continue;
				}
				dfs(v, vertice);
			}
		};
		sizet cont = 0;
		for(sizet k = 0; k < n; k++){
	//		std::cout << k << " " << visited[k] << std::endl;
			if(!visited[k]){
				cont++;
				dfs(k,k);
			}
		}

		answers.push_back(cont);
	}
//	std::cout << "termino" << std::endl;
	for(sizet i = 0; i < answers.size(); i++){
		std::cout << "Case " << i+1 << ": " << answers[i] << "\n";
	}

}
