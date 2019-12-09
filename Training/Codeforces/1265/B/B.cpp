#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }
        int minp = n + 1;
        int maxp = -1;
        for (int i = 0; i < n; ++i) {

            maxp = max(pos[i + 1], maxp);
            minp = min(pos[i + 1], minp);

                        if (maxp - minp == i) {
                cout << "1";
            } else {
                cout << "0";
            }
        }

        cout << "\n";
    }
}
