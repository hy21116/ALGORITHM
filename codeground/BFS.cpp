#include <stdio.h>
#include <malloc.h>

typedef struct node{
	int value;
	node* next;
}Node;

typedef struct queue{
	Node* front;
	Node* rear;
	int size;
}Queue;

void queue_init(Queue* q){
	q->front = q->rear = NULL;
	q->size = 0;
}

void queue_push(Queue* q, int val){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;
	newNode->next = NULL;
	q->size++;
	if (q->front == NULL && q->rear == NULL){
		q->front = q->rear = newNode;
	}
	else{
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

void queue_pop(Queue* q){
	if (q->front->next == NULL){
		q->size--;
		q->front = q->rear = NULL;
	}
	else if (q->front->next != NULL){
		Node* removeNode = q->front;
		q->front = q->front->next;
		q->size--;
		free(removeNode);
	}
}

int queue_front(Queue *q){
	return q->front->value;
}

int graph[1010][1010];
int visited[1010];
int node, edge;
int row, col;

void bfs(int cur){
	Queue q;
	queue_init(&q);
	visited[cur] = 1;
	queue_push(&q, cur);
	while (q.size){
		int front = queue_front(&q);
		queue_pop(&q);
		printf("%d ", front);
		for (int i = 1; i <= edge; i++){
			if (visited[i] != 0 || graph[front][i] == 0) continue;
			visited[i] = 1;
			queue_push(&q, i);
		}
	}
}


int main(){
	scanf("%d %d", &node, &edge);
	for (int i = 0; i < edge; i++){
		scanf("%d %d", &row, &col);
		graph[row][col] = 1;
	}

	bfs(1);

	return 0;
}