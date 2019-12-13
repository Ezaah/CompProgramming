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
    int n = irand(1, 200);
    int k = irand(1, 5);
    cout << n << " " << k << "\n";
    for (sizet i = 0; i < n; ++i) {
        int val = irand(0, 2);
        char chr = 'a' + val;
        cout << chr;
    }
    cout << "\n";
    set<char> used;
    for (sizet i = 0; i < k; ++i) {
        int val = irand(0, 25);
        while (used.count(val)) {
            val = irand(0, 25);
        }
        used.insert(val);
        char chr = 'a' + val;
        cout << chr << " ";
    }
    cout << "\n";
}
