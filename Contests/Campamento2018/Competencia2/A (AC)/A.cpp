#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

inline vector<string> split(const string& str,const  string& sep){
	vector<string> tokens;
	auto pos = str.find_first_not_of(sep);
	while(pos != string::npos){
		auto end_pos = str.find_first_of(sep, pos +1);
		tokens.emplace_back(str, pos, end_pos - pos);
		if(end_pos == string::npos){
			break;
		}
		pos = str.find_first_not_of(sep, end_pos +1);
	}
	return tokens;
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	vector<string> str;
	string input;
	getline(cin, input);

	while(true){
		str = split(input, " ");
		for(sizet i = 1; i < str.size(); ++i){
			string modifiers = "";
			string variable = "";
			for(char chr : str[i]){
				if(isalpha(chr)){
					variable.push_back(chr);
				}else{
					if(chr == ']')					
						modifiers.insert(0,"[");
					else if(chr == '[')
						modifiers.insert(0,"]");
					else if(chr == '*' || chr == '&')
						modifiers.insert(0, {chr});
					else
						continue;

				}
			}

			string prefix = str[0] + modifiers;
			cout << prefix << " " << variable << ";\n";
		}
		if(getline(cin, input))
			cout << "\n";
		else
			break;
	}
}
