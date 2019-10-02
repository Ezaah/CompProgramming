#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n;
	cin >> n;
	vector<vector<string>> table(n, vector<string>(n));
	for(sizet i = 0; i <n; ++i){
		for(sizet j = 0; j < n; ++j){
			cin >> table[i][j];
		}
	}

	priority_queue<sizet> pq;
	pq.push(0);
	vector<pair<sizet,sizet>> directions = {{-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1, 1}, {0,1},{-1,1}};
	function<void(sizet, sizet, vector<vector<bool>>, sizet, sizet)> traverse;
	traverse = [&](sizet x, sizet y, vector<vector<bool>> visited, sizet points, sizet dir){
	//	cout << x << " " << y << " with " << dir << " and points "<<  points<<endl;
		if(table[x][y] == "1"){
			points++;
		}else if(table[x][y] == "#"){
			points *=2;
		}else if(table[x][y] == "-1"){
			points--;
		}else if(table[x][y] == "*"){
			return;
		}
	//	cout << "points updated" << endl;
//		cout << "pushing points = " << points << endl;
		pq.push(points);
		visited[x][y] = 1;
		//cout << "starting to look neighbors" << endl;
		for(sizet h = 0; h < 8; ++h){
			sizet i = x + directions[h].first;
			sizet j = y + directions[h].second;

			if(i == -1 || i == n || j == -1  || j == n)
				continue;
			if(visited[i][j]){
				continue;
			}
			//cout << " visiting " << i << " " << j << " with dir " << h << endl;
			if(h == dir){
				traverse(i,j, visited, points, dir);
			}else{
				traverse(i,j, visited, points - 1, h);
			}
		}
	};

	for(sizet i = 0; i < 8; ++i){
//		cout << "starting with dir " << i << endl;
		vector<vector<bool>> visited (n, vector<bool>(n, 0));
		traverse(n-1,0, visited, 0, i);
	}
	cout << pq.top() << "\n";

}
