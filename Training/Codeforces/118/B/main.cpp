#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n + 1; ++i) {
        int x = i - n;
        for (int j = 0; j < n; ++j) {
            if (x > -1) {
                cout << x << " ";
            } else {
                cout << "  ";
            }

            ++x;
        }

        cout << x;

        for (int j = n; j < 2 * n + 1; ++j) {
            --x;
            if (x > -1) {
                cout << " " << x;
            }
        }
        cout << "\n";
    }

    for (int i = n + 1; i < 2 * n + 1; ++i) {
        int x = n - i;
        for (int j = 0; j < n; ++j) {
            if (x > -1) {
                cout << x << " ";
            } else {
                cout << "  ";
            }
            ++x;
        }

        cout << x;

        for (int j = n; j < 2 * n + 1; ++j) {
            --x;
            if (x > -1) {
                cout << " " << x;
            }
        }
        cout << "\n";
    }

    // for (int i = 0; i < 2 * n + 1; ++i) {
    //     for (int j = 0; j < 2 * n + 1; ++j) {
    //         if (table[i][j] < 0) {
    //             cout << " ";
    //         } else {
    //             cout << table[i][j];
    //         }
    //         if (j + 1 < 2 * n + 1) {
    //             cout << " ";
    //         } else {
    //             cout << "\n";
    //         }
    //     }
    // }
}
