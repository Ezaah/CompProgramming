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
        map<int, int, greater<int>> freq;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            if (freq.count(p[i])) {
                freq[p[i]]++;
            } else {
                freq[p[i]] = 1;
            }
        }

        int sum = 0;
        int g = 0;
        int s = 0;
        int b = 0;
        for (auto &elem : freq) {
            if (sum + elem.second > n / 2) {
                break;
            }
            sum += elem.second;
            if (g == 0) {
                g = elem.second;
            } else if (s <= g) {
                s += elem.second;
            } else {
                b += elem.second;
            }
        }

        if (g == 0 || s == 0 || b == 0 || s <= g || b <= g) {
            cout << "0 0 0\n";
        } else {
            cout << g << " " << s << " " << b << "\n";
        }
    }
}
