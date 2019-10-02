#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;
typedef vector<sizet> vctr;
void print_array(vctr v) {
  for (auto &val : v) {
    cout << val << " ";
  }
  cout << endl;
}
void flip(sizet i, vctr &v) {
  sizet j = 0;
//  print_array(v);
  while (i > j) {
    sizet temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    --i;
    ++j;
  }
//  print_array(v);
//  cout << endl;
}

inline std::vector<std::string> split(const std::string &str,
                                      const std::string &sep) {
  std::vector<std::string> tokens;
  auto pos = str.find_first_not_of(sep);
  while (pos != std::string::npos) {
    auto end_pos = str.find_first_of(sep, pos + 1);
    tokens.emplace_back(str, pos, end_pos - pos);
    if (end_pos == std::string::npos)
      break;
    pos = str.find_first_not_of(sep, end_pos + 1);
  }
  return tokens;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string input;
//  getline(cin, input);
  while (getline(cin, input)) {
    vector<string> fixed = split(input, " ");
    vctr v;
    for (auto &number : fixed) {
      v.push_back(std::stoll(number));
    }
    vctr original = v;
    sizet n = v.size();
    vctr s;
    for (sizet i = 0; i < n; ++i) {
//	cout << "iteration " << i+1 << endl;
	sizet max_v = -1;
	sizet max_index = -1;
      for (sizet j = 0; j < n - i; ++j) {
	//cout << "comparing " << v[j] << " vs " << max_v << endl;
	// 
	// sea k la posición dondee esta el maximo del arreglo entre [0, n - i]
	// Si k == n-1 => Continuea
	// Si k == 0 => flip(n - i) && add (n - i)
	// Si k != n-1 => flip(k) && add (8 - k) a la solución
	// 
	if(max_v < v[j]){
		max_v = v[j];
		max_index = j;
	}
      }
	if(max_index == n - i - 1){
		continue;
	}else{
		if(max_index != 0){
//			print_array(v);
			flip(max_index, v);
//			cout << "adding " << n - max_index << " to sol\n";
			s.push_back(n-max_index);
		}
//		print_array(v);
		flip(n - i - 1, v);
//		cout << "adding " << i + 1  << " to sol" << endl;
//		print_array(v);
//		cout << endl;
		s.push_back(i+1);
	}
      

    }
    for (sizet i = 0; i < original.size(); ++i) {
      cout << original[i];
      if (i < n - 1) {
        cout << " ";
      }
    }
    cout << "\n";
    for (auto& flip_value : s) {
	    cout << flip_value << " ";
    }
    cout << "0\n";
  //  cout << "new tests" << endl;
  }
}
