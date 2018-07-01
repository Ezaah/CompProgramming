#include <bits/stdc++.h>
#include "segment_tree.hpp"

// TODO: Update edges. Calculate distance between 2 nodes. Documentate code... fuck me

template <typename data>
void debug(const std::vector<data>& array){
  for(size_t i = 0; i < array.size(); i++){
    std::cout << array[i]<< " ";
  }
  std::cout << std::endl;
}


template <typename Weight, typename BinaryOp>
class heavy_light_decomposition {

  std::vector<size_t> parent, depth;
  std::vector<size_t> head, chain_index, values_index;
  cpl::segment_tree<Weight, BinaryOp> stree;
  BinaryOp operation{};

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
    values_index.resize(num_vertices);
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

    // Segment Tree init
    stree.assign(values.begin(), values.end());
  }

  size_t lca(size_t u, size_t v) const {
    while(chain_index[u] != chain_index[v]){
      if(depth[head[u]] > depth[head[v]]){
        u = parent[head[u]];
      }else{
        v = parent[head[v]];
      }
    }
    return (depth[u] > depth[v]) ? v : u;
  }

  Weight query(const size_t u, const size_t v) const {
    const size_t middle = lca(u,v);

    std::function<Weight(size_t, size_t)> climb_chain;
    climb_chain = [&](size_t u, size_t v){
      Weight ans = 0;
      while(true){
        if(chain_index[u] == chain_index[v]){
          ans = operation(ans, stree.accumulate(values_index[v] + 1, values_index[u] + 1));
          break;
        }
        ans = operation(ans, stree.accumulate(values_index[head[u]], values_index[u] + 1));
        u = parent[head[u]];
      }
      return ans;
    };

    return operation(climb_chain(u, middle), climb_chain(v, middle));
  }

};
