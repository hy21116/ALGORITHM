#include <stdio.h>

#define MAX 20

typedef struct queue{
	int y;
	int x;
}Queue;

int N;
int map[MAX][MAX];
int dy[] = { -1, -1, 1, 1 };
int dx[] = { -1, 1, 1, -1 };
int number[101];
int startY, startX;
int max, sum, prevDir, dirCount;
int visited[MAX*MAX];
//Queue visited[MAX*MAX];
//int idx;

void dfs(int y, int x){
	int idx = y * N + x;
	visited[idx] = 1;
	number[map[y][x]] = 1;
	sum += 1;
	if (dirCount > 4)
		return;

	for (int i = 0; i < 4; i++){
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
			continue;
		int nextIdx = nextY * N + nextX;
		if (dirCount >= 3 && nextX == startX && nextY == startY){
			if (max < sum)
				max = sum;
		}
		else if (!visited[nextIdx] && !number[map[nextY][nextX]]){
			if (prevDir != i)
				dirCount++;
			int temp = prevDir;
			prevDir = i;
			dfs(nextY, nextX);
			visited[nextY * N + nextX] = 0;
			number[map[nextY][nextX]] = 0;
			sum -= 1;
			if (prevDir != temp)
				dirCount--;
			prevDir = temp;
		}
	}

}


int main(){
	int T;

	//freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++){
		// initialize
		max = -1;

		// input
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				scanf("%d", &map[i][j]);
			}
		}

		// dfs
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				// initialize
				startY = i;
				startX = j;
				sum = 0;
				dirCount = 0;
				prevDir = -1;
				for (int k = 0; k < 101; k++)
					number[k] = 0;
				for (int k = 0; k < N*N; k++)
					visited[k] = 0;

				dfs(startY, startX);
			}
		}

		printf("#%d %d\n", test_case, max);
	}

	return 0;
}