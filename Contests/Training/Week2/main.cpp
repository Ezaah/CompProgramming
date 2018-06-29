#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

class directed_graph {
	vector<vector<sizet>> adj_list;
public:
	directed_graph(const sizet vertices) : adj_list(vertices){}
	void add_edge(sizet u, sizet v){
		adj_list[u].push_back(v);
	}

	vector<sizet> out_edges(const sizet vertex){
		return adj_list[vertex];
	}

};

int main(){
	directed_graph graph(8);
	graph.add_edge(7,0);
	graph.add_edge(1,4);
	graph.add_edge(1,6);
	graph.add_edge(2,7);
	graph.add_edge(3,4);
	graph.add_edge(3,7);
	graph.add_edge(4,5);
	graph.add_edge(7,6);
	
	vector<sizet> state(8);
	vector<sizet> output;
	function<void(sizet)> visit;
	visit = [&](sizet n){
		if(state[n] == 2){
			return;
		}
		if(state[n] == 1){
			cout << "Not a dag\n";
		}
		state[n] = 1;
		cout << "temporary mark " << n << "\n";
		for(auto u : graph.out_edges(n)){
			cout << "visiting " << u << "\n";
			visit(u);
		}
		state[n] = 2;
		cout << "permanent mark " << n << "\n";
		output.push_back(n);
	};

	visit(0);
	for(sizet i = 7; i > -1; i--){
		cout << output[i] << " ";
	}
}
