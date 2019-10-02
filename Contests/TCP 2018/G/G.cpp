#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

constexpr double pi(){
	return atan2(0,-1);
}

struct Point {
	sizet x;
	sizet y;
};


bool valid(Point& a, Point& b){
	sizet dot = a.x*b.x + a.y*b.y;
	sizet det = a.x*b.y - a.y*b.x;
	double angle = atan2(det, dot);
	return (angle == pi()/2 || angle == -pi()/2);
}
void debug_point(Point& a){
	cout << "(" << a.x << "," << a.y << ")";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet n;
	cin >> n;
	vector<Point> points;
	for(sizet i = 0; i < n; ++i){
		sizet x,y;
		cin >> x >> y;
		points.push_back({x,y});
	}
	sizet cnt = 0;
	sizet cnt2 = 0;
	for(sizet i = 0; i < n; ++i){
	       for(sizet j = 0; j < n; j++){
		       for(sizet k = 0; k < n; ++k){
			       cnt2++;
			     Point v1 = {points[j].x - points[i].x, points[j].y - points[i].y};
			     Point v2 = {points[k].x - points[i].x, points[k].y - points[i].y};
			     if(valid(v1,v2)){
				cnt++;
			     }
					    
		       }
	       }
	}
	cout << cnt <<" " << cnt2 << "\n";

}
