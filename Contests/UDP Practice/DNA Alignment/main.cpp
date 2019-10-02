#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

/*
 * typedef vector<sizet> vect;
 * typedef pair<sizet,sizet> pares;
 */
sizet mod_add(sizet a, sizet b, sizet mod = 1e9 + 7){
	if(a < mod - b)
		return a+b;
	return a - (mod - b);
}

sizet mod_mul(sizet a, sizet b, sizet mod = 1e9 + 7){
	sizet result = 0;
	while(b > 0){
		if(b%2)
			result = mod_add(a, result, mod);
		a = mod_add(a,a,mod);
		b /= 2;
	}
	return result;
}

sizet mod_pow(sizet a, sizet b, sizet mod = 1e9 + 7){
	sizet result = 1;
	while(b > 0){
		if(b%2)
			result = mod_mul(result, a, mod);
		a = mod_mul(a,a,mod);
		b /=2;
	}
	return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sizet len;
  string word;
  cin >> len >> word;
  unordered_map<char, sizet> options = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
  for (auto &chr : word) {
    options[chr]++;
  }
  string max_letters = "";
  sizet max_freq = -1;
  for (auto &opt : options) {
    if (opt.second == max_freq) {
      max_letters += opt.first;
    } else if (opt.second > max_freq) {
      max_letters = opt.first;
      max_freq = opt.second;
    }
  }
  cout << mod_pow(max_letters.size(), len)<< "\n";
}
