#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print_v(vector<int> a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> ab, cd, bc;

    while (a > 0 && b > 0) {
        ab.push_back(0);
        ab.push_back(1);
        a--;
        b--;
    }
    while (c > 0 && d > 0) {
        cd.push_back(2);
        cd.push_back(3);
        c--;
        d--;
    }

    while (b > 0 && c > 0) {
        bc.push_back(2);
        bc.push_back(1);
        b--;
        c--;
    }
    if (b != 0) {
        ab.insert(ab.begin(), 1);
        b--;
    }
    if (c != 0) {
        cd.push_back(2);
        c--;
    }

    if (bc.empty() && ab.empty() && d != 0) {
        cd.insert(cd.begin(), 3);
        d--;
    }

    if (bc.empty() && cd.empty() && a != 0) {
        ab.push_back(0);
        a--;
    }
    vector<int> seq;

    for (int x : ab) {
        seq.push_back(x);
    }

    for (int x : bc) {
        seq.push_back(x);
    }
    for (int x : cd) {
        seq.push_back(x);
    }

    // cout << a << " " << b << " " << c << " " << d << endl;
    // print_v(seq);
    if (a != 0 || b != 0 || c != 0 || d != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    print_v(seq);
}
