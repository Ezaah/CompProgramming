#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int irand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(stoi(argv[1]));
    int n = irand(1, 10);

    set<int> values;
    for (int i = 0; i < n; ++i) {
        values.insert(i + 1);
    }

    cout << n << "\n";
    for (sizet i = 0; i < n; ++i) {
        int incog = irand(0, 1);
        if (incog) {
            cout << "0 ";
        } else {
            int x = irand(1, n);
            while (!values.count(x)) {
                x = irand(1, n);
            }
            values.erase(x);
            cout << x << " ";
        }
    }
    cout << endl;
}
