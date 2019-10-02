#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

constexpr double pi(){
       return atan2(0,-1);
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	double a;
	while(cin >> a){
		double alfa = (12*a*a - 3*sqrt(3)*a*a - 2*pi()*a*a)/3;
		double beta = (-12*a*a + 6*sqrt(3)*a*a + pi()*a*a)/3;
		double gamma = (-3*sqrt(3)*a*a + 3*a*a + pi()*a*a)/3;
		printf("%.3f %.3f %.3f\n", gamma, beta, alfa);
	}
}
