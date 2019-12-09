#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        string word;
        cin >> word;

        bool impossible = 0;
        for (int i = 0; i + 1 < word.size(); ++i) {
            if (word[i] == word[i + 1] && word[i] != '?') {
                impossible = 1;
                break;
            }
        }

        if (impossible) {
            cout << "-1\n";
            continue;
        }

        vector<char> options = {'a', 'b', 'c'};
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '?') {
                for (char &opt : options) {
                    if (i == 0 && word[i + 1] != opt) {
                        word[i] = opt;
                        break;
                    } else if (i == word.size() - 1 && word[i - 1] != opt) {
                        word[i] = opt;
                        break;
                    } else if (opt != word[i - 1] && opt != word[i + 1]) {
                        word[i] = opt;
                        break;
                    }
                }
            }
        }

        cout << word << "\n";
    }
}
