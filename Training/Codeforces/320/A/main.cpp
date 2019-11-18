#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string number;
    cin >> number;

    bool magic = 0;
    size_t i = 0;
    while (i < number.size()) {
        if (number[i] != '1') {
            magic = 1;
            break;
        }

        if (number[i] == '1') {
            i++;
        }

        if (i == number.size()) {
            break;
        }
        if (number[i] == '4') {
            i++;
        }
        if (i == number.size()) {
            break;
        }
        if (number[i] == '4') {
            i++;
        }
        if (i == number.size()) {
            break;
        }
    }

    if (magic) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
