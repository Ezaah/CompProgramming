#include <bits/stdc++.h>
using namespace std;
// reescribir long long para hacerlo mas corto :D
typedef long long sizet;

int main() {
  // Optimizacion de inputs
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sizet n, m;
  while (cin >> m >> n) {
    vector<pair<sizet, sizet>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<char>> table(m);

    for (sizet i = 0; i < m; ++i) {
      for (sizet j = 0; j < n; ++j) {
        char chr;
        cin >> chr;
        table[i].push_back(chr);
      }
    }
    sizet mijid_x, mijid_y;
    cin >> mijid_x >> mijid_y;

    char land = table[mijid_x][mijid_y];

    vector<vector<bool>> visited(m, vector<bool>(n));
    vector<vector<sizet>> sizes(m, vector<sizet>(n));

    function<void(sizet, sizet, char, sizet, sizet, bool)> dfs;
    dfs = [&](sizet x, sizet y, char land, sizet i, sizet j, bool mirid) {
      visited[x][y] = 1;
      if (mirid)
        sizes[x][y] = -1;
      else
        sizes[i][j]++;
      for (sizet d = 0; d < 4; d++) {
        sizet a, b;
        a = x + directions[d].first;
        b = y + directions[d].second;
        if (a == -1) {
          a = 0;
        } else if (a == m) {
          a = m - 1;
        }

        if (b == -1) {
          b = n - 1;
        } else if (b == n) {
          b = 0;
        }
        if (!visited[a][b] && table[a][b] == land) {
          dfs(a, b, land, i, j, mirid);
        }
      }
    };
    dfs(mijid_x, mijid_y, land, mijid_x, mijid_y, true);
    sizet max_continent = 0;
    for (sizet h = 0; h < m; h++) {
      for (sizet k = 0; k < n; k++) {
        if (table[h][k] == land && !visited[h][k]) {
          dfs(h, k, land, h, k, false);
          max_continent = max(max_continent, sizes[h][k]);
        }
      }
    }

    /*		for(auto row : sizes){
                            for(auto col : row){
                                    cout << col << " ";
                            }
                            cout << "\n";
                    }*/
    cout << max_continent << "\n";
  }

  return 0;
}
