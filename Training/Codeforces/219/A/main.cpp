#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    string word;
    cin >> word;

    map<char, int> freq;

    for (auto &letter : word) {
        if (freq.find(letter) == freq.end()) {
            freq[letter] = 1;
        } else {
            freq[letter]++;
        }
    }

    string output = "";
    bool impossible = 0;

    for (auto &elem : freq) {
        if (elem.second % k != 0) {
            impossible = 1;
            break;
        }
    }

    if (impossible) {
        cout << "-1\n";
    } else {
        string aux = "";
        for (auto &elem : freq) {
            for (int i = 0; i < elem.second / k; ++i) {
                aux += elem.first;
            }
        }

        for (int i = 0; i < k; ++i) {
            output += aux;
        }

        cout << output << "\n";
    }
}
