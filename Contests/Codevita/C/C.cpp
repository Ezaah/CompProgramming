#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

string lowercase(string &a ){
	for(auto& chr : a){
		if(!isalpha(chr)){
			continue;
		}
		chr = tolower(chr);
	}
	return a;
}

inline std::vector<std::string> split(const std::string& str,
                                      const std::string& sep) {
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

inline string join(const vector<string> & str, const string &sep){
	string joined = "";
	for(size_t i = 0; i < str.size(); ++i){
		joined += str[i];
		if(i < str.size() - 1){
			joined += sep;
		}
	}
	return joined;
}

template <typename RandomIt1, typename RandomIt2>
std::size_t levenshtein_distance(RandomIt1 first1, RandomIt1 last1,
                                 RandomIt2 first2, RandomIt2 last2) {
  using std::size_t;
  using std::min;
  auto min3 = [](size_t x, size_t y, size_t z) { return min(x, min(y, z)); };

  const size_t num_rows = (last1 - first1) + 1;
  const size_t num_cols = (last2 - first2) + 1;
  std::vector<size_t> storage(2 * num_cols);
  auto prev = storage.begin(); // previous row
  auto curr = prev + num_cols; // current row

  std::iota(prev, prev + num_cols, size_t{0});

  for (size_t i = 1; i < num_rows; ++i) {
    curr[0] = i;
    for (size_t j = 1; j < num_cols; ++j) {
      if (first1[i - 1] == first2[j - 1])
        curr[j] = prev[j - 1];
      else
        curr[j] = min3(prev[j], curr[j - 1], prev[j - 1]) + 1;
    }
    std::swap(curr, prev);
  }
  return prev[num_cols - 1];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string n_str;
	getline(cin, n_str);
	sizet n = stoi(n_str);
	vector<string> correct(n);
	for(sizet i = 0; i < n; ++i){
		string aux;
		getline(cin, aux);
//		cout << aux << endl;
		correct[i] = lowercase(aux);
	}
	string m_str;
	getline(cin, m_str);
	sizet m = stoi(m_str);
	vector<vector<string>> fix(m, vector<string>());
	for(sizet i = 0; i < m; ++i){
		string aux;
		getline(cin, aux);
	//	cout << aux << endl;
		fix[i] = split(lowercase(aux), " ");
	}
	map<string, sizet> institutes;
	for(sizet i = 0; i < m; ++i){
			for(size_t k = 0; k < fix[i].size(); ++k){
				for(sizet j = 0; j < n; ++j){
					if(levenshtein_distance(fix[i][k].begin(), fix[i][k].end(), correct[j].begin(), correct[j].end()) <= 3){
						fix[i][k] = correct[j];
						break;
					}
			}
		}
		string fixed = join(fix[i], " ");
		//cout << fixed << endl;
		if(institutes.find(fixed) != institutes.end()){
			institutes[fixed]++;
		}else{
			institutes[fixed] = 1;
		}
	}

	for(auto& bucket : institutes){
		cout << bucket.first << ":" << bucket.second << "\n";
	}
}
