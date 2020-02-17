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

    cout << "1\n";
    int n = irand(1, 50);
    cout << n << "\n";
    for (int i = 0; i < 2 * n; ++i) {
        cout << irand(1, 100) << " ";
    }
    cout << "\n";
}
