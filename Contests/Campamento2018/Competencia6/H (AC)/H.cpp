#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

struct direction {
  sizet x;
  sizet y;
  string dir;
};

void printer(vector<vector<string>> &arr) {
  for (auto &i : arr) {
    for (auto &val : i) {
      cout << val << " ";
    }
    cout << endl;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  vector<direction> directions = {
      {-1, -1, "LU"}, {0, -1, "U"}, {1, -1, "RU"}, {1, 0, "R"},
      {1, 1, "RD"},   {0, 1, "D"},  {-1, 1, "LD"}, {-1, 0, "L"},
  };
  vector<direction> directions_inv = {
      {-1, -1, "RD"}, {0, -1, "D"}, {1, -1, "LD"}, {1, 0, "L"},
      {1, 1, "LU"},   {0, 1, "U"},  {-1, 1, "RU"}, {-1, 0, "R"},
  };

  vector<vector<string>> table(8, vector<string>(8, "-1"));
  map<char, int> decipher = {
      {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5},
      {'g', 6}, {'h', 7}, {'1', 7}, {'2', 6}, {'3', 5}, {'4', 4},
      {'5', 3}, {'6', 2}, {'7', 1}, {'8', 0},
  };
  string start, end;
  cin >> start >> end;
  sizet xs = decipher[start[0]];
  sizet ys = decipher[start[1]];
  sizet xf = decipher[end[0]];
  sizet yf = decipher[end[1]];
  queue<direction> que;
  que.push({xs, ys, "0"});

  while (!que.empty()) {
    auto direct = que.front();
    que.pop();

    sizet i = direct.x;
    sizet j = direct.y;
    if (table[j][i] != "-1")
      continue;
    table[j][i] = direct.dir;
    for (auto &dir : directions) {
      sizet x = i + dir.x;
      sizet y = j + dir.y;
      if (x<0 | y<0 | x> 7 | y> 7) {
        continue;
      }
      que.push({x, y, dir.dir});
    }
  }
  vector<string> path;
  while (table[yf][xf] != "0") {
    for (auto &dir : directions_inv) {
      if (table[yf][xf] == dir.dir) {
        path.insert(path.begin(), table[yf][xf]);
        xf += dir.x;
        yf += dir.y;
      }
    }
  }

  cout << path.size() << "\n";
  for (auto &way : path) {
    cout << way << "\n";
  }
}
