#include <stdio.h>

#define MAX 100

typedef struct data{
	int val;
	int dir;
	int max;
}Data;

typedef struct queue{
	int row;
	int col;
	int val;
	int dir;
}Queue;

int N, M, K;
Data map[MAX][MAX];
Queue myQ[2000];
int front, rear;
int dirRow[4] = { -1, 0, 0, 1 };
int dirCol[4] = { 0, -1, 1, 0 };

int main(){
	int T;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++){
		// initialize 
		for (int i = 0; i < MAX; i++){
			for (int j = 0; j < MAX; j++){
				map[i][j].val = 0;
				map[i][j].dir = 0;
				map[i][j].max = 0;
			}
		}

		// input
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < K; i++){
			int row, col, val, dir;
			scanf("%d %d %d %d", &row, &col, &val, &dir);
			// convert to myDir (up : 0, down : 3, left : 1, right : 2)
			switch (dir){
			case 1:
				dir = 0;
				break;
			case 2:
				dir = 3;
				break;
			case 3:
				dir = 1;
				break;
			case 4:
				dir = 2;
				break;
			}
			map[row][col].val = val;
			map[row][col].dir = dir;
		}

		for (int i = 0; i < M; i++){
			// initialize queue
			front = rear = 0;

			// push into queue
			for (int y = 0; y < N; y++){
				for (int x = 0; x < N; x++){
					if (map[y][x].val != 0){
						myQ[rear].row = y;
						myQ[rear].col = x;
						myQ[rear].val = map[y][x].val;
						myQ[rear].dir = map[y][x].dir;
						rear++;
					}
				}
			}
			// check red cell and push into queue
			int size = rear - front;
			while (size--){
				int nextR = myQ[front].row + dirRow[myQ[front].dir];
				int nextC = myQ[front].col + dirCol[myQ[front].dir];
				if (nextR == 0 || nextR == N-1 || nextC == 0 || nextC == N-1){
					//if (myQ[front].val / 2 != 0){
						myQ[rear].row = nextR;
						myQ[rear].col = nextC;
						myQ[rear].val = myQ[front].val / 2;
						myQ[rear].dir = 3 - myQ[front].dir;
						rear++;
					//}
				}
				else{
					myQ[rear].row = nextR;
					myQ[rear].col = nextC;
					myQ[rear].val = myQ[front].val;
					myQ[rear].dir = myQ[front].dir;
					rear++;
				}
				front++;
			}

			// initialize & update map
			for (int y = 0; y < N; y++){
				for (int x = 0; x < N; x++){
					map[y][x].val = 0;
					map[y][x].dir = 0;
					map[y][x].max = 0;
				}
			}
			size = rear - front;
			while (size--){
				int r = myQ[front].row;
				int c = myQ[front].col;
				if (map[r][c].max < myQ[front].val){
					map[r][c].max = myQ[front].val;
					map[r][c].dir = myQ[front].dir;
				}
				map[r][c].val += myQ[front].val;
				front++;
			}
		}

		// check the number
		int result = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (map[i][j].val != 0)
					result += map[i][j].val;
			}
		}

		printf("#%d %d\n", test_case, result);
	}

	return 0;
}