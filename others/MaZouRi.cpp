/*
 * 马走日算法
 *
 *  Created on: 2019年3月20日
 *      Author: 17500
 */
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;

int m, n;
int way;
bool matrix[10][10];
int x_add[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int y_add[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool ifLegal(int x, int y)
{
	return !(x < 0 || y < 0 || x >= m || y >= n);
}

void dfs(int x, int y, int cnt)
{
	/* 不可访问 */
	if(!ifLegal(x, y) || matrix[x][y]) {
		return;
	}

	/* 标记为已访问 */
	cnt++;
	matrix[x][y] = true;

	/* 判断是否全部访问到 */
	if ((m * n) == cnt) {
		way++;
		return;
	}

	/* 继续深度遍历 */
	for (int i = 0; i < 8; i++) {
		bool tmp = matrix[x + x_add[i]][y + y_add[i]];
		dfs(x + x_add[i], y + y_add[i], cnt);
		matrix[x + x_add[i]][y + y_add[i]] = tmp;
	}
}

int main()
{
	int N;
	cin>>N;
	for (int i = 0; i < N; i++) {
		int x, y;
		int cnt = 0;

		cin>>m>>n>>x>>y;

		dfs(x, y, cnt);
		printf("ways:%d\n", way);
	}

	return 0;
}
