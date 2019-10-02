#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet n;
	cin >> n;
	unordered_map<char, string> codes= { {'0', "0000"}, {'1', "0001"}, {'2', "0010"},{'3', "0011"},{'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},{'8', "1000"}, {'9', "1001"},{'a', "1010"}, {'b',"1011"},{'c', "1100"},{'d',"1101"},{'e',"1110"},{'f',"1111"}};
	while(n--){
		sizet m;
		cin >> m;
		stringstream ss;
		ss << m;
		string bit_hex = "";
		for(auto& chr : ss.str()){
			bit_hex += codes[chr];
		}
		bitset<16> decimal(m);
		bitset<16> hexa(bit_hex);
		cout << decimal.count() << " " << hexa.count() << "\n";
//		cout << decimal.to_string() << " " << hexa.to_string() << "\n";
	}

}
