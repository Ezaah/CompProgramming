#include "graph.hpp"
#include "heavy_light_decomposition.hpp"

struct shallower {
  const int &operator()(const int &lhs, const int &rhs) const {
    return lhs > rhs ? lhs : rhs;
  }
};

int main() {
  Graph<long long int> graph(21);
  graph.add_edge(0, 1, 4);
  graph.add_edge(0, 2, 21);
  graph.add_edge(0, 3, 92);
  graph.add_edge(1, 4, 36);
  graph.add_edge(1, 5, 40);
  graph.add_edge(1, 6, 25);
  graph.add_edge(2, 7, 91);
  graph.add_edge(2, 8, 2);
  graph.add_edge(3, 9, 11);
  graph.add_edge(3, 10, 43);
  graph.add_edge(4, 11, 78);
  graph.add_edge(6, 12, 51);
  graph.add_edge(8, 13, 93);
  graph.add_edge(9, 14, 39);
  graph.add_edge(10, 15, 59);
  graph.add_edge(11, 16, 46);
  graph.add_edge(13, 17, 20);
  graph.add_edge(15, 18, 6);
  graph.add_edge(15, 19, 70);
  graph.add_edge(16, 20, 10);
  heavy_light_decomposition<long long int, shallower> hld(graph, 0);
  std::cout << "Query of max path between vertices 20 and 0" << std::endl;
  std::cout << "EXPECTED 78 !----! GOT " << hld.query(20, 0) << std::endl;
  std::cout << "Query of max path between vertices 17 and 18" << std::endl;
  std::cout << "EXPECTED 93 !----! GOT " << hld.query(17, 18) << std::endl;
  std::cout << "Query of max path between vertices 6 and 8" << std::endl;
  std::cout << "EXPECTED 25 !----! GOT " << hld.query(6, 8) << std::endl;
  std::cout << "Query of max path between vertices 5 and 19" << std::endl;
  std::cout << "EXPECTED 92 !----! GOT " << hld.query(5, 19) << std::endl;

  // std::vector<int> array = {
  //   -1,4,36,78,46,10,40,25,51,21,2,93,20,91,92,43,59,6,70,11,39
  // };
  // cpl::segment_tree<int, shallower> stree;
  // stree.assign(array.begin(), array.end());
  // std::cout <<stree.accumulate(2,3) << std::endl;
}
