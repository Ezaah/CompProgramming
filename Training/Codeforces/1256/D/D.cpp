#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void print_bits(string a) { cout << a << endl; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll tests;
  cin >> tests;
  while (tests--) {
    ll n, k;
    cin >> n >> k;
    string bitstr;
    cin >> bitstr;

    vector<ll> positions;
    ll first_0 = bitstr.find_first_of('0');
    ll wall = 0;
    if (first_0 == -1 || is_sorted(bitstr.begin(), bitstr.end())) {
      cout << bitstr << "\n";
      continue;
    }

    if (first_0 != 0) {
      positions.push_back(first_0);
    } else {
      wall = 1;
    }

    for (ll i = first_0 + 1; i < n; ++i) {
      if (bitstr[i] == '0') {
        positions.push_back(i);
      }
    }
    // cout << bitstr << endl;
    for (ll i = 0; i < (ll)positions.size(); ++i) {

      if (k == 0) {
        break;
      }

      ll dist = positions[i] - wall;
      // cout << wall << " " << positions[i] << " " << k << " " << dist << endl;
      if (dist > k) {
	wall += (dist - k);
	dist = k;

      }
      // cout << wall << " " << positions[i] << " " << k << " " << dist << endl;

      swap(bitstr[wall], bitstr[positions[i]]);
      wall++;
      k -= dist;
      // cout << bitstr << endl;
    }

    cout << bitstr << "\n";
  }
}
