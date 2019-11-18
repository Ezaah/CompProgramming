#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v_coins, p_coins, v_heads, p_heads;
    cin >> v_coins >> p_coins >> v_heads >> p_heads;

    vector<pair<int, int>> outcomes;

    for (int i = v_heads; i <= v_coins; ++i) {
        for (int j = p_heads; j <= p_coins; ++j) {
            if (i > j) {
                outcomes.push_back(make_pair(i, j));
            } else {
                break;
            }
        }
    }

    sort(outcomes.begin(), outcomes.end());

    cout << outcomes.size() << "\n";
    for (auto &par : outcomes) {
        cout << par.first << " " << par.second << "\n";
    }
}
