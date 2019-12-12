#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i];
    }
    
    int change25 = 0;
    int change50 = 0;
    int change100 = 0;
    bool impossible = 0;
    for (int i = 0; i < n; ++i) {
      int change = people[i] - 25;
      if(people[i] == 100){
        change100++;
      }else if(people[i] == 50){
        change50++;
      }else{
        change25++;
      }
      if(change == 75){
        if(change50 > 0 && change25 > 0){
          change50--;
          change25--;
        }else if(change25 > 2){
          change25-=3;
        }else{
          impossible = 1;
          break;
        }
      }else if(change == 25){
        if(change25 > 0){
          change25--;
        }else{
          impossible = 1;
          break;
        }
      }
    }

    if (impossible) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
