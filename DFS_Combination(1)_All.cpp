#include <stdio.h>

#define N 5

bool visited[N];
int arr[N];

void dfs(int x){
<<<<<<< HEAD
	if (x == N){
		for (int i = 0; i < N; i++){
			if (visited[i])
				printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else{
		visited[x] = true;
		dfs(x + 1);
		visited[x] = false;
		dfs(x + 1);
	}
=======
    if(x == N){
        for(int i = 0; i < N; i++){
            if(visited[i])
                printf('%d ', arr[i]);
        }
        printf("\n");
    }
    else{
        visited[x] = true;
        dfs(x + 1)
        visited[x] = false;
        dfs(x + 1)
    }
>>>>>>> 2d8deaab772bc0a8b7349de39a0e534f65e5aac6
}


int main(){
<<<<<<< HEAD
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dfs(0);

	return 0;
=======
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    dfs(0)

    return 0;
>>>>>>> 2d8deaab772bc0a8b7349de39a0e534f65e5aac6
}