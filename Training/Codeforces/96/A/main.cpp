#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    cin >> a;

    bool n = a.find("0000000") != string::npos;
    bool m = a.find("1111111") != string::npos;

    if (n || m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
