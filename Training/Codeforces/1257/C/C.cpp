#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> numbers;
ll n;

void print_arr(ll i, ll j) {
    cout << "Subarray (" << i << "," << j << ")\n";
    for (; i <= j; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tests;
    cin >> tests;
    while (tests--) {
        cin >> n;
        numbers.resize(n);
        for (ll i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        ll min_dist = 1e9;
        vector<ll> pos(n + 1, -1);
        for (ll i = 0; i < n; ++i) {
            if (pos[numbers[i]] != -1) {
                min_dist = min(min_dist, i - pos[numbers[i]] + 1);
            }

            pos[numbers[i]] = i;
        }
        if (min_dist == 1e9) {
            min_dist = -1;
        }
        cout << min_dist << "\n";
    }
}
