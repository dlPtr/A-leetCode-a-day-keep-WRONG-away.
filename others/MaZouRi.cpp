/*
 * �������㷨
 *
 *  Created on: 2019��3��20��
 *      Author: 17500
 */
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

int m, n;
int way;

int x_add[8] = {2, 2, 1, -1, -2, -2, 1, -1};
int y_add[8] = {1, -1, 2, 2, 1, -1, -2, -2};

bool ifLegal(int x, int y)
{
	return !(x < 0 || y < 0 || x >= m || y >= n);
}

void dfs(int x, int y, int cnt, bool matrix[10][10])
{
	/* ���ɷ��� */
	if(!ifLegal(x, y) || matrix[x][y]) {
		return;
	}

	/* ���Ϊ�ѷ��� */
	cnt++;
	matrix[x][y] = true;

	/* �ж��Ƿ�ȫ�����ʵ� */
	if ((m * n) == cnt) {
		way++;
		return;
	}

	/* ������ȱ��� */
	for (int i = 0; i < 8; i++) {
		bool tmp = matrix[x + x_add[i]][y + y_add[i]];
		dfs(x + x_add[i], y + y_add[i], cnt, matrix);
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
		bool matrix[10][10] = {{false}};

		cin>>m>>n>>x>>y;

		dfs(x, y, cnt, matrix);
		printf("ways:%d\n", way);
	}

	return 0;
}
