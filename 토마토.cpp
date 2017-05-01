#include<iostream>
#include <queue>

using namespace std;

int box[1010][1010];
int rc[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

struct point {
	int row, col, day;
	point(int _row, int _col, int _day) : row(_row), col(_col), day(_day) {}

};
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	queue <point> q;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &box[i][j]);
			// 1을 q에 넣느다.
			if (box[i][j] == 1){
				q.push(point(i, j, 0));
			}
		}
	}
	int day=0;
	int f = -1, r = 0;
	while (!q.empty()) {
		point now = q.front();
		q.pop();
		day = day < now.day ? now.day : day;
		int row = now.row, col = now.col;
		for (int i = 0; i < 4; i++){
			int gorow = row + rc[i][0];
			int gocol = col + rc[i][1];
			if (box[gorow][gocol] == 0 && gorow < m && gorow >= 0 && gocol < n && gocol >= 0){
				box[gorow][gocol] = 1;
				q.push(point(gorow, gocol, now.day + 1));
			}
		}
	}
	bool sw = false;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (box[i][j] == 0){
				printf("-1");
				sw = true;
			}
		}
	}
	if (!sw){
		printf("%d", day);
	}
	return 0;
}