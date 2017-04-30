#include<iostream>
using namespace std;

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
int q[3][100010];
char a[100][100];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%s", a[i]);
	}

	q[0][0] = 0;
	q[1][0] = 0;
	q[2][0] = 1;
	a[0][0] = 0;

	int f = -1, r = 0;
	int gorow = 0, gocol = 0;

	while (f < r){
		int row = q[0][++f];
		int col = q[1][f];
		if (row == n - 1 && col == m - 1){
			printf("%d", q[2][f]);
			break;
		}

		for (int i = 0; i < 4; i++){
			gorow = row + dir[i][0];
			gocol = col + dir[i][1];

			if (gorow < 0 || gorow >= n || gocol < 0 || gocol >= m || a[gorow][gocol] == '0'){
				continue;
			}
			q[0][++r] = gorow;
			q[1][r] = gocol;
			q[2][r] = q[2][f] + 1;
			a[gorow][gocol] = '0';
		}
	}


	return 0;
}