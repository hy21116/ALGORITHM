#include <stdio.h>

#define MAX 20

int map[MAX][MAX];
int height[MAX];
int N, X;

int abs(int a){
	return a > 0 ? a : -a;
}

bool isFlatBetween(int s, int e){
	if (s < 0 || e >= N)
		return false;

	for (int i = s; i < e; i++){
		if (height[i] != height[i + 1])
			return false;
	}

	return true;
}

bool canRunway(){
	for (int i = 0; i < N - 1; i++){
		if (abs(height[i] - height[i + 1]) >= 2)
			return false;
	}

	bool* upSlope = new bool[N];
	bool* downSlope = new bool[N];
	for (int i = 0; i < N; i++)
		upSlope[i] = downSlope[i] = false;
	for (int i = 0; i < N - 1; i++){
		if (height[i] + 1 == height[i + 1]){
			int s = i - X + 1;
			int e = i;
			if (isFlatBetween(s, e)){
				for (int j = s; j <= e; j++)
					upSlope[j] = true;
			}
			else
				return false;
		}
		else if (height[i] - 1 == height[i + 1]){
			int s = i + 1;
			int e = i + X;
			if (isFlatBetween(s, e)){
				for (int j = s; j <= e; j++)
					downSlope[j] = true;
			}
			else
				return false;
		}
	}

	for (int i = 0; i < N; i++){
		if (upSlope[i] && downSlope[i])
			return false;
	}

	return true;
}

int main(){
	int test_case, T;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++){
		scanf("%d %d", &N, &X);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);
		}

		int rowCnt, colCnt;
		rowCnt = colCnt = 0;

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++)
				height[j] = map[i][j];

			if (canRunway())
				rowCnt++;
		}

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++)
				height[j] = map[j][i];

			if (canRunway())
				colCnt++;
		}

		printf("%d %d\n", test_case, rowCnt + colCnt);
	}

	return 0;
}