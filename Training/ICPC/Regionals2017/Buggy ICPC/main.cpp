#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

bool is_vocal(char &chr) {
  return chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u';
}

sizet count(string &word) {
  // cout << word << endl;
  // There's only one letter and there's only one way to write it!
  if (word.size() == 1)
    return 1;
  // if the last letter is a vocal and the first is consonant then is invalid
  if (!is_vocal(word.front()) && is_vocal(word.back()))
    return 0;

  if (is_vocal(word.front())) {
    // First is vocal, so i have to see the case of the word just has been
    // reversed
    string reversed = word;
    reverse(reversed.begin(), reversed.end());
    reversed.pop_back();
    if (!is_vocal(word.back())) {
      // The last is not vocal so i have 2 cases: removing the first letter or
      // removing the last
      word.pop_back();
      return count(reversed) + count(word);
    } else {
      // The last is vocal so my only choice is removing the first
      return count(reversed);
    }
  } else {
    // The first isn't vocal so i can only remove the last
    word.pop_back();
    return count(word);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string input;
  cin >> input;
  // while (cin >> input)
  cout << count(input) << "\n";
}
