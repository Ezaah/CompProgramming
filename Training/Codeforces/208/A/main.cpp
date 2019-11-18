#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string song;
    cin >> song;

    ll i = 0;
    while (i < (ll)song.size()) {
        if (song.substr(i, 3) == "WUB") {
            song.replace(i, 3, " ");
        }
        i++;
    }
    auto last = unique(song.begin(), song.end(), [](char x, char y) { return x == ' ' && y == ' '; });
    song.erase(last, song.end());
    if (song.front() == ' ') {
        song.erase(song.begin());
    }
    if (song.back() == ' ') {
        song.pop_back();
    }
    cout << song << endl;
}
