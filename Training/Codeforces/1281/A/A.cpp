#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int tests;
    cin >> tests;

    while(tests--){
        string text; 
        cin >> text;
        
        reverse(text.begin(), text.end());

        if(text.substr(0,2) == "op"){
            cout << "FILIPINO\n";
            continue;
        }
        string end = text.substr(0,4);
        if(end == "used" || end == "usam"){
            cout << "JAPANESE\n";
            continue;
        }
        end = text.substr(0,5);

        if(end == "adinm"){
            cout << "KOREAN\n";
        }
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
