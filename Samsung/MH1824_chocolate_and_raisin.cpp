#include<stdio.h>

#define MAX 50

int N, M, R;
int map[MAX][MAX];
bool visited[100];
bool checked[100];
int arr[100];
int sum = 987654321;

void perm(int step){
	if (step == R){
#if 0
		printf("[");
		for (int i = 1; i <= R; i++){
			printf("%d ", arr[i]);
		}
		puts("]");
#endif
		sum = 987654321; // it can be problem -> much bigger
		for (int i = 0; i < 100; i++)
			checked[i] = 0;
		
		int temp = 0;
		for (int i = 1; i <= R; i++){
			if (temp > sum)
				break;
                
			if (arr[i] <= M - 1){ // col
				int start, end;
				for (start = arr[i]; start >= 0; start--){
					if (checked[start])
						break;
				}
				for (end = arr[i]; end < M; end++){
					if (checked[end]){
						end -= 1;
						break;
					}
				}

				for (int x = start; x <= end; x++){
					for (int y = 0; y < N; y++)
						temp += map[y][x];
				}
			} 
			else{ // row
				int start, end;
				for (start = arr[i] - M + 1; start >= 0; start--){
					if (checked[M - 1 +start])
						break;
				}
				for (end = arr[i] - M + 1; end < N; end++){
					if (checked[end]){
						end -= 1;
						break;
					}
				}

				for (int y = start; y <= end; y++){
					for (int x = 0; x < M; x++)
						temp += map[y][x];
				}
			}
			checked[arr[i]] = 1;
		}

		if (temp < sum)
			sum = temp;
		return;
	}

	step++;
	for (int i = 1; i <= R; i++){
		if (!visited[i]){
			visited[i] = 1;
			arr[step] = i;
			perm(step);
			visited[i] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case, T;
	
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){
		for (int i = 0; i < 100; i++){
			visited[i] = 0;
			arr[i] = 0;
		}
		
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				scanf("%d", &map[i][j]);
			}
		}
#if 0
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				printf("%d ", map[i][j]);
			}
			puts("");
		}
#endif
		R = N - 1 + M - 1; // permutation N == R here
		if (!R){ // for case N = 1, M = 1
			sum = map[0][0];
		}
		else{
			perm(0);
		}

		printf("#%d %d\n", test_case, sum);
	}
	return 0;
}