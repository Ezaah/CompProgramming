#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print_set(vector<ll> &a) {
    cout << a.size() << " ";
    for (ll i = 0; i < (ll)a.size(); ++i) {
        cout << a[i];
        if (i + 1 < (ll)a.size()) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> elems(n);
    for (ll i = 0; i < n; ++i) {
        cin >> elems[i];
    }

    sort(elems.begin(), elems.end());

    vector<ll> a, b, c;
    ll less_0 = count_if(elems.begin(), elems.end(), [](ll x) { return x < 0; });
    for (ll i = 0; i < n; ++i) {
        if (elems[i] == 0) {
            c.push_back(elems[i]);
        } else if (elems[i] > 0) {
            b.push_back(elems[i]);
        }
    }

    auto last = remove_if(elems.begin(), elems.end(), [](ll x) { return x >= 0; });
    elems.erase(last, elems.end());

    if (less_0 % 2 == 0) {
        c.push_back(elems.back());
        elems.pop_back();
    }

    if (b.size() == 0) {
        a.push_back(elems.back());
        elems.pop_back();
        for (ll i = 0; i < (ll)elems.size(); ++i) {
            b.push_back(elems[i]);
        }
    } else {
        for (ll i = 0; i < (ll)elems.size(); ++i) {
            a.push_back(elems[i]);
        }
    }

    print_set(a);
    print_set(b);
    print_set(c);
}
