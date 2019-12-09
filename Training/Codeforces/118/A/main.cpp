#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    cin >> word;

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

    for (auto &letter : word) {
        letter = towlower(letter);
    }
    auto last = remove_if(word.begin(), word.end(), [&](char x) {
        return vowels.find(x) != vowels.end();
    });

    word.erase(last, word.end());

        string output = "";
    for (auto &letter : word) {
        output += ".";
        output += letter;
    }

    cout << output << "\n";
}
