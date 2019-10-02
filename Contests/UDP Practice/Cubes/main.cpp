#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;
typedef pair<sizet, sizet> pares;
/*
 * typedef vector<sizet> vect;
 *
 */

sizet mod_add(sizet a, sizet b, sizet mod = 1000000009) {
  if (a < mod - b)
    return a + b;
  return a - (mod - b);
}

sizet mod_mul(sizet a, sizet b, sizet mod = 1000000009) {
  sizet result = 0;
  while (b > 0) {
    if (b % 2)
      result = mod_add(a, result, mod);
    a = mod_add(a, a, mod);
    b /= 2;
  }
  return result;
}

sizet mod_pow(sizet a, sizet b, sizet mod = 1000000009) {
  sizet result = 1;
  while (b > 0) {
    if (b % 2)
      result = mod_mul(a, result, mod);
    a = mod_mul(a, a, mod);
    b /= 2;
  }
  return result;
}
class Graph {
  vector<set<sizet>> inedges, outedges;

public:
  Graph(sizet num_vertices) : inedges(num_vertices), outedges(num_vertices) {}
  void add_edge(sizet u, sizet v) {
    //  cout << "connecting " << u << " " << v << endl;
    outedges[u].insert(v);
    inedges[v].insert(u);
  }

  void remove_vertex(sizet u, sizet v) {
    outedges[u].erase(v);
    outedges[v].erase(u);
  }

  set<sizet> in_edges(sizet u) { return inedges[u]; }

  set<sizet> out_edges(sizet u) { return outedges[u]; }

  sizet outs(sizet u) { return outedges[u].size(); }
};

bool comparer(pares &a, pares &b) { return a.second > b.second; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sizet cubes;
  cin >> cubes;
  map<pares, sizet> indexes;
  vector<pares> cube_positions(cubes);
  Graph graph(cubes);
  for (sizet i = 0; i < cubes; ++i) {
    sizet x, y;
    cin >> x >> y;
    cube_positions[i] = {x, y};
    indexes[{x, y}] = i;
  }
  sort(cube_positions.begin(), cube_positions.end(), comparer);
  vector<pares> directions = {{-1, -1}, {0, -1}, {1, -1}};
  set<sizet> leafs;
  for (auto &par : cube_positions) {
    if (par.second == 0)
      continue;
    for (auto &dir : directions) {
      pares newpar = {par.first + dir.first, par.second + dir.second};
      if (indexes.find(newpar) != indexes.end()) {
        graph.add_edge(indexes[newpar], indexes[par]);
      }
    }
  }

  for (sizet i = 0; i < cubes; ++i) {
    if (graph.outs(i) == 0) {
      // cout << i << " is in the set" << endl;
      leafs.insert(i);
    }
  }
  bool maximize = 1;
  vector<sizet> sol;
  while (!leafs.empty()) {
    sizet best;
    if (maximize) {
      best = *leafs.rbegin();
      sol.push_back(best);
    } else {
      best = *leafs.begin();
      sol.push_back(best);
    }
    // cout << "removing " << best << " from the set" << endl;
    leafs.erase(best);
    for (auto &v : graph.in_edges(best)) {
      graph.remove_vertex(v, best);
      if (graph.outs(v) == 0) {
        leafs.insert(v);
        // cout << "adding " << v << " to the set" << endl;
      }
    }

    maximize = !maximize;
  }
  sizet result = 0;
  sizet pos = cubes - 1;
  for (auto &num : sol) {
    // cout << num << " ";
    result = mod_add(mod_mul(num, mod_pow(cubes, pos)), result);
    pos--;
  }
  // cout << endl;
  cout << result << "\n";
}
