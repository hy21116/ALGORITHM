#include <stdio.h>

#define N 5 // n

bool visited[N];
int arr[N];

void dfs(int x){
	if (x == N){
		int count = 0;
		for (int i = 0; i < N; i++){
			if (visited[i])
				count += 1;
		}
		if (count == 3){ // r            
			for (int i = 0; i < N; i++){
				if (visited[i])
					printf("%d ", arr[i]);
			}
			printf("\n");
		}
	}
	else{
		visited[x] = true;
		dfs(x + 1);
		visited[x] = false;
		dfs(x + 1);
	}
}


int main(){
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dfs(0);

	return 0;
}