#include <stdio.h>

int graph[1010][1010];
int visited[1010];
int node, edge;
int row, col;

void dfs(int cur){
	visited[cur] = 1;
	printf("%d ", cur);
	for (int i = 1; i <= edge; i++){
		if (visited[i] != 0 || graph[cur][i] == 0) continue; 
		dfs(i);
	}
}


int main(){
	scanf("%d %d", &node, &edge);
	for (int i = 0; i < edge; i++){
		scanf("%d %d", &row, &col);
		graph[row][col] = 1;
	}

	dfs(1);

	return 0;
}