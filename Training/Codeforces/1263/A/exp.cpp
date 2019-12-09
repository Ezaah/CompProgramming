#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        vector<ll> rgb(3);
        cin >> rgb[0] >> rgb[1] >> rgb[2];

        ll cnt = 0;
        sort(rgb.rbegin(), rgb.rend());
        while (rgb[1] != 0 || rgb[2] != 0) {
            if (rgb[2] != 0) {
                cnt++;
                rgb[2]--;
                rgb[0]--;
            } else {
                cnt += rgb[1];
                rgb[0] -= rgb[1];
                rgb[1] = 0;
            }

            if (rgb[1] > rgb[0]) {
                swap(rgb[0], rgb[1]);
            }
        }

        // cnt += rgb[2];
        // if (rgb[0] == rgb[1]) {
        //     rgb[0] -= rgb[2] / 2;
        //     rgb[1] -= rgb[2] / 2;
        //     if (rgb[2] % 2 == 1) {
        //         rgb[1]--;
        //     }
        // } else {
        //     rgb[0] -= rgb[2];
        // }

        // if (rgb[1] > rgb[0]) {
        //     rgb[1] = rgb[0];
        // }

        // cnt += rgb[1];

        cout << cnt << "\n";
    }
}
