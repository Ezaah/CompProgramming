#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

char next_rotation(char actual) {
  if (actual == '+') {
    return '+';
  } else if (actual == '-') {
    return '|';
  } else if (actual == '|') {
    return '-';
  } else if (actual == '^') {
    return '>';
  } else if (actual == '>') {
    return 'v';
  } else if (actual == 'v') {
    return '<';
  } else if (actual == '<') {
    return '^';
  } else if (actual == 'L') {
    return 'U';
  } else if (actual == 'U') {
    return 'R';
  } else if (actual == 'R') {
    return 'D';
  } else if (actual == 'D') {
    return 'L';
  } else {
    return '*';
  }
}
/*
        Orientation:
        1 => a is looking for a top match while b is looking for a bottom match
        2 => a is looking for a left match while b is looking for a right match
        3 => a is looking for a bottom match while b is looking for a top match
        4 => a is looking for a right match while b is looking for a left match
*/
bool can_connect(char &a, char &b, sizet orientation) {
  if (a == '*' || b == '*') {
    return false;
  }
  if (orientation == 1) {
    if (a != '+' and a != '|' and a != '^' and a != 'L' and a != 'R' and
        a != 'D') {
      return false;
    }
    if (b != '+' and b != '|' and b != 'v' and b != 'L' and b != 'R' and
        b != 'U') {
      return false;
    }
    return true;
  } else if (orientation == 2) {
    if (a != '+' and a != '-' and a != '<' and a != 'R' and a != 'D' and
        a != 'U') {
      return false;
    }
    if (b != '+' and b != '-' and b != '>' and b != 'L' and b != 'D' and
        b != 'U') {
      return false;
    }
    return true;
  } else if (orientation == 3) {
    if (a != '+' and a != '|' and a != 'v' and a != 'L' and a != 'R' and
        a != 'U') {
      return false;
    }
    if (b != '+' and b != '|' and b != '^' and b != 'L' and b != 'R' and
        b != 'D') {
      return false;
    }
    return true;
  } else if (orientation == 4) {
    if (a != '+' and a != '-' and a != '>' and a != 'L' and a != 'D' and
        a != 'U') {
      return false;
    }
    if (b != '+' and b != '-' and b != '<' and b != 'R' and b != 'D' and
        b != 'U') {
      return false;
    }
    return true;
  }
  return false;
}
struct dirs {
  sizet k;
  sizet i;
  sizet j;
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  sizet height, width;
  cin >> height >> width;
  vector<vector<vector<char>>> table(
      4, vector<vector<char>>(height, vector<char>(width)));
  for (sizet i = 0; i < height; ++i) {
    for (sizet j = 0; j < width; ++j) {
      cin >> table[0][i][j];
    }
  }
  sizet hero_x, hero_y;
  sizet minotaur_x, minotaur_y;
  cin >> hero_x >> hero_y >> minotaur_x >> minotaur_y;
  hero_x--;
  hero_y--;
  minotaur_x--;
  minotaur_y--;

  for (sizet k = 0; k < 3; ++k) {
    for (sizet i = 0; i < height; ++i) {
      for (sizet j = 0; j < width; ++j) {
        table[k + 1][i][j] = next_rotation(table[k][i][j]);
      }
    }
  }
  vector<dirs> directions = {
      {1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
  vector<vector<vector<bool>>> visited(
      4, vector<vector<bool>>(height, vector<bool>(width)));
  sizet distance = -1;
  queue<pair<dirs, sizet>> que;
  que.push({{0, hero_x, hero_y}, 0});
  while (!que.empty()) {
    dirs point = que.front().first;
    sizet dist = que.front().second;
    que.pop();
    sizet k = point.k;
    sizet i = point.i;
    sizet j = point.j;
    if (visited[k][i][j]) {
      continue;
    }
    visited[k][i][j] = 1;
    if (i == minotaur_x && j == minotaur_y) {
      distance = dist;
      break;
    }
    for (auto &dir : directions) {
      sizet newk = (k + dir.k) % 4;
      sizet newi = dir.i + i;
      sizet newj = dir.j + j;

      if (newi == -1 || newi == height || newj == -1 || newj == width) {
        continue;
      }
      if (visited[newk][newi][newj]) {
        continue;
      }
      if (dir.k) {
        que.push({{newk, newi, newj}, dist + 1});
      } else {
        if (dir.i == 1) {
          if (can_connect(table[k][i][j], table[newk][newi][newj], 3)) {
            que.push({{newk, newi, newj}, dist + 1});
          }
        } else if (dir.i == -1) {
          if (can_connect(table[k][i][j], table[newk][newi][newj], 1)) {
            que.push({{newk, newi, newj}, dist + 1});
          }
        } else if (dir.j == 1) {
          if (can_connect(table[k][i][j], table[newk][newi][newj], 4)) {
            que.push({{newk, newi, newj}, dist + 1});
          }
        } else if (dir.j == -1) {
          if (can_connect(table[k][i][j], table[newk][newi][newj], 2)) {
            que.push({{newk, newi, newj}, dist + 1});
          }
        }
      }
    }
  }

  cout << distance << endl;
}
