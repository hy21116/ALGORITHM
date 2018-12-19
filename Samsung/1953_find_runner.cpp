#include <stdio.h>

#define MAX 50

typedef struct data{
	int r;
	int c;
	int val;
}Data;

int N, M, R, C, L;
int map[MAX][MAX];
int visited[3000];
Data queue[100000];
int front, rear;
int count;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int check(int curY, int curX, int i){
	int temp = map[curY + dy[i]][curX + dx[i]];
	if (i == 0){
		if (temp == 1 || temp == 2 || temp == 5 || temp == 6)
			return 1;
	}
	else if (i == 1){
		if(temp == 1 || temp == 2 || temp == 4 || temp == 7)
			return 1;
	}
	else if (i == 2){
		if(temp == 1 || temp == 3 || temp == 4 || temp == 5)
			return 1;
	}
	else if (i == 3){
		if(temp == 1 || temp == 3 || temp == 6 || temp == 7)
			return 1;
	}
	return 0;
}

int inMap(int curY, int curX, int i){
	if (curY + dy[i] >= 0 && curY + dy[i] < N && curX + dx[i] >= 0 && curX + dx[i] < M)
		return 1;
	return 0;
}

void push(int r, int c, int val){
	queue[rear].r = r;
	queue[rear].c = c;
	queue[rear].val = val;
	rear++;
	visited[r * M + c] = 1;
}

void bfs(int r, int c){
	visited[r * M + c] = 1;
	queue[rear].r = r;
	queue[rear].c = c;
	queue[rear].val = map[r][c];
	rear++;

	while (front != rear){
		count++;
		if (count == L)
			return;

		int size = rear - front;
		for (int i = 0; i < size; i++){
			int curY = queue[front].r;
			int curX = queue[front].c;
			int curVal = queue[front].val;
			front++;

			if (curVal == 1){
				for (int i = 0; i < 4; i++){
					int temp = (curY + dy[i]) * M + curX + dx[i];
					int tempY = curY + dy[i];
					int tempX = curX + dx[i];
					if (check(curY, curX, i) && !visited[temp] && inMap(curY, curX, i))
						push(tempY, tempX, map[tempY][tempX]);
				}
			}
			else if (curVal == 2){
				for (int i = 0; i < 2; i++){
					int temp = (curY + dy[i]) * M + curX + dx[i];
					int tempY = curY + dy[i];
					int tempX = curX + dx[i];
					if (check(curY, curX, i) && !visited[temp] && inMap(curY, curX, i))
						push(tempY, tempX, map[tempY][tempX]);
				}
			}
			else if (curVal == 3){
				for (int i = 2; i < 4; i++){
					int temp = (curY + dy[i]) * M + curX + dx[i];
					int tempY = curY + dy[i];
					int tempX = curX + dx[i];
					if (check(curY, curX, i) && !visited[temp] && inMap(curY, curX, i))
						push(tempY, tempX, map[tempY][tempX]);
				}
			}
			else if (curVal == 4){
				for (int i = 0; i < 4; i++){
					if (i == 0 || i == 3){
						int temp = (curY + dy[i]) * M + curX + dx[i];
						int tempY = curY + dy[i];
						int tempX = curX + dx[i];
						if (check(curY, curX, i) && !visited[temp] && inMap(curY, curX, i))
							push(tempY, tempX, map[tempY][tempX]);
					}
				}
			}
			else if (curVal == 5){
				for (int i = 0; i < 4; i++){
					if (i == 1 || i == 3){
						int temp = (curY + dy[i]) * M + curX + dx[i];
						int tempY = curY + dy[i];
						int tempX = curX + dx[i];
						if (check(curY, curX, i) && !visited[temp] && inMap(curY, curX, i))
							push(tempY, tempX, map[tempY][tempX]);
					}
				}
			}
			else if (curVal == 6){
				for (int i = 0; i < 4; i++){
					if (i == 1 || i == 2){
						int temp = (curY + dy[i]) * M + curX + dx[i];
						int tempY = curY + dy[i];
						int tempX = curX + dx[i];
						if (check(curY, curX, i) && !visited[temp] && inMap(curY, curX, i))
							push(tempY, tempX, map[tempY][tempX]);
					}
				}
			}
			else if (curVal == 7){
				for (int i = 0; i < 4; i++){
					if (i == 0 || i == 2){
						int temp = (curY + dy[i]) * M + curX + dx[i];
						int tempY = curY + dy[i];
						int tempX = curX + dx[i];
						if (check(curY, curX, i) && !visited[temp] && inMap(curY, curX, i))
							push(tempY, tempX, map[tempY][tempX]);
					}
				}
			}

		}
	}

}


int main(){
	int T;

	//freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++){
		// initialize
		front = rear = 0;
		count = 0;
		for (int i = 0; i < 3000; i++)
			visited[i] = 0;
		for (int i = 0; i < 100000; i++){
			queue[i].r = 0;
			queue[i].c = 0;
			queue[i].val = 0;
		}

		// input
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				scanf("%d", &map[i][j]);
			}
		}

		bfs(R, C);

		// calculate the region
		int result = 0;
		for (int i = 0; i < N * M; i++){
			if (visited[i])
				result++;
		}

		printf("#%d %d\n", test_case, result);
	}

	return 0;
}