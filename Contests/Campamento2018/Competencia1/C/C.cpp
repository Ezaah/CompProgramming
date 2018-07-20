#include <bits/stdc++.h>
typedef long long sizet;


class Graph {
	std::vector< std::vector<sizet> > adj_list;

public:
	Graph(sizet num_vertices) : adj_list(num_vertices) {}

	void add_edge(sizet u, sizet v){
		adj_list[u].push_back(v);
	}

	std::vector<sizet> out_edges(sizet u){
		return adj_list[u];
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sizet n;
	std::cin >> n;
	Graph graph(26);
	// for(sizet i = 0; i < 25; i++){
	// 	graph.add_edge(i,i+1);
	// }
	std::vector<std::string> words(n);
	for(sizet i = 0; i < n; i++){
		std::cin >> words[i];
	}

	bool impossible = 0;
	bool base_is_larger = 0;
	for(sizet i = 0; i < n-1; i++){
		std::string base = words[i];
		std::string compared = words[i+1];
		if(base.size() > compared.size()){
			base_is_larger = 1;
		}
		for(sizet j = 0; j < base.size(); j++){
			if(base[j] != compared[j]){
				graph.add_edge(base[j] - 'a', compared[j] - 'a');
				break;
			}
			if(j+1 == compared.size() && base_is_larger){
				impossible = 1;
				break;
			}
		}
	}
	if(impossible){
		std::cout << "Impossible\n";
		return 0;
	}

	std::vector<sizet> states(26, 0);
	std::vector<sizet> completed;
	std::function<void(sizet)> dfs;
	dfs = [&](sizet vertice){
		states[vertice] = 1;
		for(auto v : graph.out_edges(vertice)){
			if(states[v] == 0){
				dfs(v);
			}else if(states[v] == 1){
				impossible = 1;
				return;
			}
		}
		states[vertice] = 2;
		completed.insert(completed.begin(), vertice);
	};

	for(sizet  i = 25; i > -1; i--){
		if(!states[i]){
			// std::cout << "starting dfs with vertex " << i << std::endl;
			dfs(i);
		}
	}
	if(impossible){
		std::cout << "Impossible\n";
	}else{
		for(auto complete : completed){
			char chr = 'a' + complete;
			std::cout << chr;
		}
		std::cout << "\n";
	}

}
