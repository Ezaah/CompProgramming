#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string english, portuguese;
  vector<pair<string, string>> inputs;
  while (cin >> portuguese >> english) {
    inputs.push_back({portuguese, english});
  }
  for (sizet i = 0; i < inputs.size(); ++i) {
    portuguese = inputs[i].first;
    english = inputs[i].second;
    bool possible = 1;
    string root, sufix;
    char tv;
    if (portuguese.size() >= 2) {
      root = portuguese.substr(0, portuguese.size() - 2);
      sufix = portuguese.substr(portuguese.size() - 2, 2);
      tv = sufix[0];
      if (sufix != "ar" && sufix != "er" && sufix != "ir") {
        possible = 0;
      }
    } else {
      possible = 0;
    }

    printf("%s (to %s)\n", portuguese.c_str(), english.c_str());
    if (not possible) {
      printf("Unknown conjugation\n");
    } else {
      char fillval = cout.fill();
      if (sufix == "ar" || sufix == "er") {
        printf("eu");
        for (sizet i = 0; i < 8; ++i) {
          printf("%c", fillval);
        }
        printf("%so\n", root.c_str());
        printf("tu");
        for (sizet i = 0; i < 8; ++i) {
          printf("%c", fillval);
        }
        printf("%s%cs\n", root.c_str(), tv);
        printf("ele/ela");
        for (sizet i = 0; i < 3; ++i) {
          printf("%c", fillval);
        }
        printf("%s%c\n", root.c_str(), tv);
        printf("n%cs", (char)243);
        for (sizet i = 0; i < 7; ++i) {
          printf("%c", fillval);
        }
        printf("%s%cmos\n", root.c_str(), tv);
        printf("v%cs", (char)243);
        for (sizet i = 0; i < 7; ++i) {
          printf("%c", fillval);
        };
        printf("%s%cis\n", root.c_str(), tv);
        printf("eles/elas");
        for (sizet i = 0; i < 1; ++i) {
          printf("%c", fillval);
        }
        printf("%s%cm\n", root.c_str(), tv);
      } else {
        printf("eu");
        for (sizet i = 0; i < 8; ++i) {
          printf("%c", fillval);
        }
        printf("%so\n", root.c_str());
        printf("tu");
        for (sizet i = 0; i < 8; ++i) {
          printf("%c", fillval);
        }
        printf("%ses\n", root.c_str());
        printf("ele/ela");
        for (sizet i = 0; i < 3; ++i) {
          printf("%c", fillval);
        }
        printf("%se\n", root.c_str());
        printf("n%cs", (char)243);
        for (sizet i = 0; i < 7; ++i) {
          printf("%c", fillval);
        }
        printf("%s%cmos\n", root.c_str(), tv);
        printf("v%cs", (char)243);
        for (sizet i = 0; i < 7; ++i) {
          printf("%c", fillval);
        };
        printf("%s%cs\n", root.c_str(), tv);
        printf("eles/elas");
        for (sizet i = 0; i < 1; ++i) {
          printf("%c", fillval);
        }
        printf("%sem\n", root.c_str());
      }
    }
    if (i < inputs.size() - 1) {
      printf("\n");
    }
  }
}
