#include <bits/stdc++.h>



int main(){
	std::string base, tester;
	std::unordered_map<char, size_t> characteres;
	std::string letras = "BDEFGHJKLNOQRSTUVWXYZ";
	for(size_t i = 0; i < 21; i++){
		characteres[letras[i]]= i;
	}
	while(std::cin >> base >> tester){
		if(base == "*")
			break;
		size_t confidence;
		std::cin >> confidence;
		
		std::function<size_t(std::string, bool)> converter;
		converter = [&](std::string str, bool format){
//			std::cout << str << " " <<str.size() << std::endl;
			size_t output = 0;
			if(format){
				size_t i = 0;
				for(int k = 2; k > -1; k--){
					output += (int(str[i]) - 'A')*std::pow(26,k);
					i++;
				}
				output *= 10000;
				for(int k = 3; i < 7; i++, k--){
					output += (int(str[i]) - '0')*std::pow(10, k);
				}
			}else{
				size_t i = 0;
				for(int k = 4; k > -1; k--){
					// A C M I P
					// 0 2 12 8 15
										
					output += characteres[str[i]]*std::pow(21,k);
					i++;
				}
				output *= 100;
				for(int k = 1; i < 7; i++, k--){
					output += (int(str[i]) - '0')*std::pow(10, k);
				}
				output+= 175760000;
			}
			return output;
		};


		size_t base_int, tester_int;
		if(!std::isalpha(tester[3]) && !std::isalpha(tester[4])){
			tester_int = converter(tester, true);
		}else if(std::isalpha(tester[3]) && std::isalpha(tester[4])){
			bool status = 0;
			for(size_t i = 0; i < 5; i++){
				if(tester[i] == 'A' || tester[i] == 'C' || tester[i] == 'M' || tester[i] == 'I' || tester[i] == 'P'){
					status = 1;
					break;
				}
			
			}
			if(status){
				std::cout << "N\n";
				continue;
			}
			tester_int = converter(tester, false);
		}else{
			std::cout << "N\n";
			continue;
		}

		if(std::isalpha(base[3])){
			base_int = converter(base, false);
		}else{
			base_int = converter(base,true);
		}
	//	std::cout << base_int << " " << tester_int << " " << base_int + confidence << std::endl;
		if(tester_int > base_int && tester_int <= base_int + confidence){
			std::cout << "Y\n";
		}else{
			std::cout << "N\n";
		}
	}
			
}
