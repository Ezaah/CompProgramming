#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string bank;
    cin >> bank;

    string last = bank.substr(0, bank.size() - 1);
    string notlast = bank.substr(0, bank.size() - 2) + bank.back();

    cout << max({stoll(bank), stoll(last), stoll(notlast)}) << endl;
}
