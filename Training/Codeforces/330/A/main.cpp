#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll rows, columns;
  cin >> rows >> columns;

  vector<vector<bool>> cake(rows, vector<bool>(columns, 1));
  vector<bool> row_possible(rows, 1);
  vector<bool> column_possible(columns, 1);
  for (ll i = 0; i < rows; ++i) {
    for (ll j = 0; j < columns; ++j) {
      char elem;
      cin >> elem;
      if (elem == 'S') {
        cake[i][j] = 0;
        row_possible[i] = 0;
        column_possible[j] = 0;
      }
    }
  }

  ll sum = 0;
  for (ll i = 0; i < rows; ++i) {
    if (row_possible[i]) {
      for (ll j = 0; j < columns; ++j) {
        if (cake[i][j]) {
          sum++;
          cake[i][j] = 0;
        }
      }
    }
  }

  for (ll i = 0; i < columns; ++i) {
    if (column_possible[i]) {
      for (ll j = 0; j < rows; ++j) {
        if (cake[j][i]) {
          sum++;
          cake[j][i] = 0;
        }
      }
    }
  }

  cout << sum << "\n";
}
