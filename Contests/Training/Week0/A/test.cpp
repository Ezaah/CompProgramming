#include <bits/stdc++.h>


int main(){
	std::cout << "A "<<int('A') - 'A' << "\n";
	std::cout << "C " << int('C') - 'A' << "\n";
	std::cout << "M " << int('M') - 'A' << "\n";
	std::cout << "I " << int('I') - 'A' << "\n";
	std::cout << "P " << int('P') - 'A' << "\n";
	std::string asd = "1234";
	for(auto  i : asd){
		std::cout << int(i) - '0';
	}
}

