#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> subjects(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            subjects[j][i] = x - '0';
        }
    }

    vector<int> students(n);
    for (int i = 0; i < m; ++i) {
        int max_val = *max_element(subjects[i].begin(), subjects[i].end());

        for (int j = 0; j < n; ++j) {
            if (subjects[i][j] == max_val) {
                students[j]++;
            }
        }
    }

    cout << count_if(students.begin(), students.end(), [](int x) { return x > 0; }) << "\n";
}
