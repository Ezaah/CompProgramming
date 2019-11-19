#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    cin >> a;

    string word = "hello";

    for (auto &chr : a) {
        if (chr == word.front()) {
            word.erase(word.begin());
            if (word.size() == 0) {
                break;
            }
        }
    }

    (word.size() == 0) ? cout << "YES\n" : cout << "NO\n";
}
