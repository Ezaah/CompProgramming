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
    while (true) {
        int val = irand(1, 26);
        if (val == 1) {
            break;
        }
    }
}
