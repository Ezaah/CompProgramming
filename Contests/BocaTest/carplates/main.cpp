#include <bits/stdc++.h>


int main(){
	std::string lower, tester;
	while(std::cin >> lower >> tester){
		size_t confidence;
		std::cin >> confidence;
		if(lower == tester && lower == "*")
			return 0;
	

		std::function<void(size_t, std::string, std::vector<size_t>&)> transformer;
	        transformer = [&](size_t letters, std::string input, std::vector<size_t>& output){
			output.resize(input.size());
			for(size_t i = 0; i < input.size(); ++i){
				if(i < letters){
					output[i] = int(input[i]) - 'A';
				}else{
					output[i] = int(input[i]) - '0';
				}
			}
		};
		bool lower_is_new = 0;
		bool tester_is_new = 0;
		std::vector<size_t> lower_int;
		if(std::isalpha(lower[3])){
			transformer(5, lower, lower_int);
			lower_is_new = 1;
		}else{
			transformer(3, lower, lower_int);
		}
		std::vector<size_t> tester_int;
		if(std::isalpha(tester[3]) == std::isalpha(tester[4]) && std::isalpha(tester[3])){
			transformer(5, tester, tester_int);
			tester_is_new = 1;
		}else if(!std::isalpha(tester[3]) == !std::isalpha(tester[4]) && !std::isalpha(tester[3])){
			transformer(3, tester, tester_int);
		}else{
			std::cout << "N\n";
			break;
		}

		std::function<void(size_t, std::vector<size_t>&, std::vector<size_t>&)> last_possible;
		last_possible = [&](size_t confidence, std::vector<size_t>& to_add, std::vector<size_t>& output){
				output.resize(to_add.size());
				if(lower_is_new){
					for(int i = 6; i > -1; --i){
				       if(i < 5){
					      confidence += to_add[i];
					      size_t mod = confidence % 26;
					      if(mod == 0 || mod == 2 || mod == 8 || mod == 12 || mod == 14)
						      mod++;
                                              output[i] = mod;
					      confidence /= 26;
				       }else{
					       confidence += to_add[i];
					       output[i] = confidence % 10;
					       confidence /= 10;
				       }
				}
			}else{
				for(int i = 6; i > -1; --i){
					if(i < 3){
						confidence += to_add[i];
						size_t mod = confidence % 26;
						if(mod == 0 || mod == 2 || mod == 8 || mod == 12 || mod == 14)
							mod++;
						output[i] = mod;
						confidence /= 26;
					}else{
						confidence += to_add[i];
						output[i] = confidence % 10;
						confidence /= 10;
					}
				}
			}
		};

		std::vector<size_t> upper_int;
		if(!lower_is_new){
			size_t to_pass = 1;
			for(size_t i = 0; i < lower_int.size(); ++i){
				if(i < 3){
					to_pass *= 26 - lower_int[i];
				}else{
					to_pass *= 10 - lower_int[i];
				}
			}
//			to_pass--;
			if(to_pass <= confidence && tester_is_new){
				transformer(5, "BBBBB00", lower_int);
				confidence -= to_pass;
				lower_is_new = 1;
			}else if(to_pass <= confidence && !tester_is_new){
				confidence = to_pass-1;
			}

		}
		last_possible(confidence, lower_int, upper_int);";

	}
	
	std::function<std::string(std::vector<size_t>&, bool)> converter;
	converter = [&](std::vector<size_t>& to_convert, bool type){
		std::string output;
		if(type){
			size_t letters = 5;
		}else{
			size_t letters = 3;
		}
		for(size_t i = 0; i < to_convert.size(); i++){
			if(i < letters){
				output.push_back(char(to_convert[i]) + 'A');
			}else{
				output.pusb_back(char(to_convert[i]) + '0');
	};
}
