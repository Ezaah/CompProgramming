#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void print_v(vector<int> a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int n;
    cin >> n;

    vector<int> blocks(n);
    for (int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        blocks[i] = x == 'W';
    }

    int ones = count(blocks.begin(), blocks.end(), 1);
    int zero = n - ones;
    vector<int> pos;

    if (ones & 1 && zero & 1) {
        cout << "-1\n";
        return 0;
    }

    if (ones == n || zero == n) {
        cout << "0\n";
        return 0;
    }

    function<void(int)> change;
    change = [&](int i) {
        blocks[i] = 1 - blocks[i];
    };
    for (int i = 0; i + 1 < n; ++i) {
        if (blocks[i]) {
            pos.push_back(i + 1);
            change(i);
            change(i + 1);
        }
        // print_v(blocks);
    }

    if (blocks[n - 1]) {
        for (int i = 0; i + 1 < n; ++i) {
            if (!blocks[i]) {
                pos.push_back(i + 1);
                change(i);
                change(i + 1);
            }
        }
        // print_v(blocks);
    }

    cout << pos.size() << "\n";
    for (int p : pos) {
        cout << p << " ";
    }
    cout << "\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
