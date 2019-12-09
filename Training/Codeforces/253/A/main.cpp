#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("output.txt");
    cout.rdbuf(out.rdbuf());

    int n, m;
    cin >> n >> m;

    bool boys = 1;
    if (n > m) {
        for (int i = 0; i < n - m; ++i) {
            cout << "B";
        }

        n = m;
        boys = 0;
    } else if (n < m) {
        for (int i = 0; i < m - n; ++i) {
            cout << "G";
        }

        m = n;
    }

    for (int i = 0; i < n + m; ++i) {
        if (boys) {
            cout << "B";
        } else {
            cout << "G";
        }

        boys = !boys;
    }
    cout << "\n";
}
