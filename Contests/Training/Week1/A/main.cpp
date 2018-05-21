#include <bits/stdc++.h>



int main(){
	size_t input_times;
	std::cin >> input_times;
	size_t output_times;
	std::cin >> output_times;
	std::vector<size_t> inputs(input_times);
	std::vector<size_t> outputs(output_times);
	std::unordered_map<size_t,size_t> times;
	for(size_t i = 0; i < input_times; i++){
		std::cin >> inputs[i];
	}
	for(size_t i = 0; i < output_times; i++){

		std::cin >> outputs[i];
	}
	size_t max_repeats = 0;
	size_t min_time;
	for(size_t i = 0; i < input_times; i++){
		for(size_t j = 0; j < output_times; j++){
			long long int time = outputs[j] - inputs[i];
			if(time < 0)
				continue;
			if(times.find(time) != times.end()){
				times[time]++;
			}else{
				times[time] = 1;
			}
			std::cout << time << " " << times[time] << " " << min_time  << " " << max_repeats << "\n";
			if(times[time] > max_repeats){
				max_repeats = times[time];
				min_time = time;
			}else if(times[time] == max_repeats && time < min_time){
				min_time = time;
			}
		}
	}
	std::cout << min_time << "\n";
}
