#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

/*
 * typedef vector<sizet> vect;
 * typedef pair<sizet,sizet> pares;
 */

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sizet n, m;
  cin >> n >> m;
  vector<bool> visited(20001);
  queue<pair<sizet, sizet>> que;
  que.push({n, 0});
  while (!que.empty()) {
    sizet number = que.front().first;
    sizet dist = que.front().second;
    que.pop();

    if (visited[number]) {
      continue;
    }
    visited[number] = 1;
    if (number == m) {
      cout << dist << "\n";
      break;
    }
    if (number < m) {
      if (!visited[2 * number]) {
        que.push({2 * number, dist + 1});
      }
    }
    if (number - 1 > 0) {
      if (!visited[number - 1]) {
        que.push({number - 1, dist + 1});
      }
    }
  }
}
