#include <stdio.h>

int N, X;
int map[20][20];
int checked[20];

int main(){
	int T, test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++){
		scanf("%d %d", &N, &X);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);
		}

		int result = 0;
		// horizontal
		for (int i = 0; i < N; i++){
			int count = 0;
			for (int k = 0; k < N; k++)
				checked[k] = 0;
			for (int j = 0; j < N - 1; j++){
				if (map[i][j] == map[i][j + 1])
					count++;
				else if (map[i][j] + 1 == map[i][j + 1]){
					if (j - X + 1 < 0)
						break;
					else{
						int tempCnt = 0;
						for (int k = j; k > j - X; k--){
							if (map[i][j] == map[i][k] && !checked[k])
								tempCnt++;
							else
								break;
						}
						if (tempCnt == X){
							count++;
							for (int k = j; k > j - X; k--)
								checked[k] = 1;
						}
						else
							break;
					}
				}
				else if (map[i][j] == map[i][j + 1] + 1){
					if (j + X >= N)
						break;
					else{
						int tempCnt = 0;
						for (int k = j + 1; k < j + 1 + X; k++){
							if (map[i][j + 1] == map[i][k] && !checked[k])
								tempCnt++;
							else
								break;
						}
						if (tempCnt == X){
							count++;
							for (int k = j + 1; k < j + 1 + X; k++)
								checked[k] = 1;
						}	
						else
							break;
					}
				}
				else
					break;
			}
			if (count == N - 1)
				result++;
		}

		// vertical
		for (int i = 0; i < N; i++){
			int count = 0;
			for (int k = 0; k < N; k++)
				checked[k] = 0;
			for (int j = 0; j < N - 1; j++){
				if (map[j][i] == map[j + 1][i])
					count++;
				else if (map[j][i] + 1 == map[j + 1][i]){
					if (j - X + 1 < 0)
						break;
					else{
						int tempCnt = 0;
						for (int k = j; k > j - X; k--){
							if (map[j][i] == map[k][i] && !checked[k])
								tempCnt++;
							else
								break;
						}
						if (tempCnt == X){
							count++;
							for (int k = j; k > j - X; k--)
								checked[k] = 1;
						}
						else
							break;
					}
				}
				else if (map[j][i] == map[j + 1][i] + 1){
					if (j + X >= N)
						break;
					else{
						int tempCnt = 0;
						for (int k = j + 1; k < j + 1 + X; k++){
							if (map[j + 1][i] == map[k][i] && !checked[k])
								tempCnt++;
							else
								break;
						}
						if (tempCnt == X){
							count++;
							for (int k = j + 1; k < j + 1 + X; k++)
								checked[k] = 1;
						}
						else
							break;
					}
				}
				else
					break;
			}
			if (count == N - 1)
				result++;
		}

		printf("#%d %d\n", test_case, result);
	}
	
	return 0;
}