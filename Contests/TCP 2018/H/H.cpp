#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

struct Point {
	sizet x;
	sizet y;
};

double distance(Point a){
	return sqrt(a.x*a.x + a.y*a.y);
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet n;
	cin >> n;
	vector<Point> points;
	for(sizet i = 0; i < n; ++i){
		sizet a,b;
		cin >> a >> b;
		points.push_back({a,b});
	}
	cout << "DISTANCE WITH ORIGIN: " << endl;
	double sum = 0;
	for(sizet i = 0; i < n; ++i){
		sum += distance(points[i]);
		cout << "D(O," << i << ") = " << distance(points[i]) << endl;
	}
	cout << "AVERAGE = " << sum/n << endl;
	sum = 0;
	sizet cnt = 0;
	cout << "\nDISTANCE WITH EACH OTHER: " << endl;
	for(sizet i = 0; i < n; ++i){
		for(sizet j = i + 1; j < n; j++){
			cnt++;
			sum += distance({points[i].x - points[j].x, points[i].y - points[j].y});
			cout << "D(" << i << "," << j << ") = " << distance({points[i].x - points[j].x, points[i].y - points[j].y}) << endl;
		}
	}
	cout << "AVERAGE = " << sum/cnt << endl;

}
