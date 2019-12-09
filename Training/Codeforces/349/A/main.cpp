#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i];
    }

    int change = 0;
    bool impossible = 0;
    for (int i = 0; i < n; ++i) {
        if (people[i] - 25 > change) {
            impossible = 1;
            break;
        }

        change += 50 - people[i];
    }

    if (impossible) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
