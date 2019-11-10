#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

void print_pairs(vector<pair<sizet, sizet>> &a) {
  for (auto x : a) {
    printf("{%lld, %lld} ", x.first, x.second);
  }
  printf("\n");
}

// bool move_up(pair<sizet, sizet> a, pair<sizet, sizet> b) {
//   if (a.second == b.second) {
//     return a.first > b.first;
//   }
//   return a.second < b.second;
// }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet n, m;
  scanf("%lld%lld", &n, &m);
  vector<sizet> post;
  unordered_map<sizet, sizet> indexes;
  vector<pair<sizet, sizet>> positions;
  vector<sizet> likes(m);
  for (sizet i = 0; i < n; ++i) {
    post.push_back(i + 1);
    indexes[i + 1] = i;
    positions.push_back(make_pair(i + 1, i + 1));
  }
  for (sizet i = 0; i < m; ++i) {
    scanf("%lld", &likes[i]);
  }

  for (sizet i = 0; i < m; ++i) {
    sizet j = indexes[likes[i]];
    if (j > 0) {
      indexes[post[j]]--;
      indexes[post[j - 1]]++;
      positions[post[j] - 1] = make_pair(min(positions[post[j] - 1].first, j),
                                         max(positions[post[j] - 1].second, j));
      positions[post[j - 1] - 1] =
          make_pair(min(positions[post[j - 1] - 1].first, j + 1),
                    max(positions[post[j - 1] - 1].second, j + 1));
      swap(post[j], post[j - 1]);
    }
    // for (sizet j = 0; j < n; ++j) {
    //   if (post[j] == likes[i] - 1) {

    //     // {0,0}, {1,1}
    //     if (j > 0) {
    //       positions[post[j]].first = min(positions[post[j]].first, j);
    //       positions[post[j]].second = max(positions[post[j]].second, j);
    //       positions[post[j - 1]].first =
    //           min(positions[post[j - 1]].first, j + 1);
    //       positions[post[j - 1]].second =
    //           max(positions[post[j - 1]].second, j + 1);
    //       swap(post[j], post[j - 1]);
    //     }
    //     break;
    //   }
    // }
  }

  for (auto par : positions) {
    printf("%lld %lld\n", par.first, par.second);
  }
}
