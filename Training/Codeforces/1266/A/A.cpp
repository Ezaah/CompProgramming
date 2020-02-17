#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int tests;
    cin >> tests;
    while (tests--) {
        string number;
        cin >> number;

        auto zero = find(number.begin(), number.end(), '0');
        if (zero == number.end()) {
            cout << "cyan\n";
            continue;
        }

        number.erase(zero);

        auto even = find_if(number.begin(), number.end(), [](char x) { return (x - '0') % 2 == 0; });

        if (even == number.end()) {
            cout << "cyan\n";
            continue;
        }
        // cout << number << endl;
        ll sum = 0;
        for (int i = 0; i < number.size(); ++i) {

            sum += number[i] - '0';
        }

        if (sum % 3 == 0) {
            cout << "red\n";
        } else {
            cout << "cyan\n";
        }
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
