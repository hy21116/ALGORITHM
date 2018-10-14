#include <stdio.h>
#include <malloc.h>

#define QMAX 1010

int graph[1010][1010];
bool visited[1010];
int nodeNum, edgeNum, start;
int row, col;
int queue[QMAX];
int front, rear;

void queue_init(){
	front = rear = 0;
}

int queue_isEmpty(){
	return front == rear;
}

int queue_isFull(){
	return rear == QMAX;
}

int queue_push(int val){
	if (queue_isFull())
		return 0;
	queue[rear] = val;
	rear++;
	return 1;
}

int queue_pop(){
	if (queue_isEmpty())
		return 0;
	front++;
	return 1;
}

int queue_size(){
	return (rear - front);
}


void dfs(int cur){
	visited[cur] = true;
	printf("%d ", cur);
	for (int i = 1; i <= nodeNum; i++){
		if (visited[i] == false && graph[cur][i] != 0)
			dfs(i);
	}
}

void bfs(int cur){
	queue_init();
	visited[cur] = true;
	queue_push(cur);
	while (queue_size()){
		int head = queue[front];
		printf("%d ", head);
		queue_pop();
		for (int i = 1; i <= nodeNum; i++){
			if (visited[i] == false && graph[head][i] != 0){
				visited[i] = true;
				queue_push(i);
			}
		}
	}
}


int main(){
	scanf("%d %d %d", &nodeNum, &edgeNum, &start);
	for (int i = 0; i < edgeNum; i++){
		scanf("%d %d", &row, &col);
		graph[row][col] = 1;
		graph[col][row] = 1;
	}

	dfs(start);
	for (int i = 0; i < 1010; i++)
		visited[i] = false;
	printf("\n");
	bfs(start);

	return 0;
}