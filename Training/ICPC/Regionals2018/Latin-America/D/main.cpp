#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> users;
    ll n;
    cin >> n;
    vector<string> mails(n);
    for (ll i = 0; i < n; ++i) {
        cin >> mails[i];
    }

    for (string &email : mails) {
        ll pos_at = email.find('@');
        string username = email.substr(0, pos_at);
        string provider = email.substr(pos_at);

        username.erase(remove(username.begin(), username.end(), '.'), username.end());

        ll pos = username.find('+');
        username = username.substr(0, pos);
        users.insert(username + provider);
    }

    cout << users.size() << "\n";
}
