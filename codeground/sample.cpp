#include <stdio.h>
#include <malloc.h>

typedef struct node{
	node* next;
	int value;
}node;

typedef struct queue{
	node* front;
	node* rear;
	int size;
}queue;

void queue_init(queue* q){
	q->front = q->rear = NULL;
	q->size = 0;
}

void queue_push(queue* q, int val){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->value = val;
	newNode->next = NULL;
	if(q->front == NULL && q->rear == NULL){
		q->front = q->rear = newNode;
		q->size++;
	}else{
		q->rear->next = newNode;
		q->rear = newNode;
		q->size++;
	}
}

void queue_pop(queue* q){
	if(q->front->next == NULL){
		q->front = q->rear = NULL;
		q->size--;
	}else if(q->front->next != NULL){
		node* removeNode = q->front;
		q->front = q->front->next;
		q->size--;
		free(removeNode);
	}
}

int queue_front(queue* q){
	return q->front->value;
}

void bfs(int cur){
	queue q;
	queue_init(&q);
	visited[cur] = 1;
	queue_push(&q, cur);
	while(q.size){
		int front = queue_front(&q);
		printf("%d ", front);
		queue_pop(&q);
		for(int i = 1; i <= edgeNum; i++){
			if(visited[i] != 0 || graph[front][i] == 0) continue;
			visited[i] = 1;
			queue_push(&q, i);
		}
	}
}

int graph[1010][1010];
int visited[1010];
int nodeNum, edgeNum;
int row, col;


int main(){
	scanf("%d %d", &nodeNum, &edgeNum);
	for(int i = 0; i < edgeNum; i++){
		scanf("%d %d", &row, &col);
		graph[row][col] = 1;
	}

	bfs(1);

	return 0;
}