#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> luckys = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777};
    bool lucky = 0;
    for (int i = 0; i < luckys.size(); ++i) {
        if (n % luckys[i] == 0) {
            lucky = 1;
            break;
        }
    }

    if (lucky) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
