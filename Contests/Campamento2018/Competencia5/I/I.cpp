#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet n;
  cin >> n;
  priority_queue<sizet> pq;
  vector<vector<sizet>> ans(n);
  sizet last = n + 1;
  for (sizet i = 0; i < n; ++i) {
    sizet value;
    cin >> value;
    pq.push(value);
    while (!pq.empty()) {
      if (pq.top() == last - 1) {
        ans[i].push_back(pq.top());
        last = pq.top();
        pq.pop();
      } else {
        break;
      }
    }
  }

  for (auto &subans : ans) {
    for (sizet i = 0; i < subans.size(); ++i) {
      cout << subans[i];
      if (i + 1 != subans.size())
        cout << " ";
    }
    cout << "\n";
  }
}
