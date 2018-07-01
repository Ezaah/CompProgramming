#include <bits/stdc++.h>
#include "segment_tree.hpp"

template <typename Weight, typename BinaryOp>
class heavy_light_decomposition {

  std::vector<size_t> parent, depth;
  std::vector<size_t> head, chain_index, values_index;
  cpl::segment_tree<Weight, BinaryOp> stree;

  template <typename data>
  void debug(const std::vector<data>& array){
    for(size_t i = 0; i < array.size(); i++){
      std::cout << array[i]<< " ";
    }
    std::cout << std::endl;
  }

public:

  template <typename Graph>
  heavy_light_decomposition(Graph& g, std::vector<Weight>& costs, const size_t root){
    const size_t num_vertices = g.num_vertices();
    // DFS Inits
    parent.resize(num_vertices);
    depth.resize(num_vertices);
    std::vector<size_t> subsizes(num_vertices, 1);
    std::vector<bool> visited(num_vertices);

    std::function<void(size_t)> dfs;
    dfs = [&](size_t u){
      visited[u] = true;
      for(auto e : g.out_edges(u)){
        size_t child = (u == g.source(e)) ? g.target(e) : g.source(e);
        if(visited[child])
          continue;
        depth[child] = depth[u] + 1;
        parent[child] = u;
        dfs(child);
        subsizes[u] += subsizes[child];
      }
    };
    dfs(root);

    //Decomposition Inits
    head.resize(num_vertices);
    chain_index.resize(num_vertices);
    values_index.resize(num_vertices, -1);
    std::vector<Weight> values(num_vertices);
    size_t ptr = 0;
    size_t chain = 0;

    std::function<void(size_t, Weight, size_t)> decomposition;
    decomposition = [&](size_t u, Weight cost, size_t father){
      chain_index[u] = chain;
      values_index[u] = ptr;
      values[ptr++] = cost;

      if(g.degree(u) == 1)
        return;

      size_t heavy_child, size = 0;
      Weight heavy_cost = Weight{0};
      for(auto e : g.out_edges(u)){
        size_t child = (u == g.source(e)) ? g.target(e) : g.source(e);
        if(child != father && subsizes[child] > size){
          size = subsizes[child];
          heavy_child = child;
          heavy_cost = costs[e];
        }
      }
      head[heavy_child] = head[u];
      decomposition(heavy_child, heavy_cost, u);

      for(auto e :  g.out_edges(u)){
        size_t child = (u == g.source(e)) ? g.target(e) : g.source(e);
        if(child != father && child != heavy_child){
          chain++;
          head[child] = child;
          decomposition(child, costs[e], u);
        }
      }
    };
    decomposition(root, Weight{0}, root);

    debug(head);
    debug(chain_index);
    debug(values_index);
    debug(values);
  }

 // QUERIES:
 // En misma cadena: [index[v] + 1, index[u] + 1)
 // En distinta cadena: [index[head[u]], index[u] + 1)
};
