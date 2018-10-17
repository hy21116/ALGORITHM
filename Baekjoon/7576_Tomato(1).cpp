#include <stdio.h>

bool visited[1000000];
int queue[1000000];
int front, rear;
int countDay = 0;

void queue_init(){
    front = rear = 0;
}

int queue_isEmpty(){
    return (front == rear);
}

int queue_isFull(){
    return (rear == 1000000);
}

int queue_push(int val){
    if(queue_isFull)
        return 0;
    queue[rear] = val;
    rear++;
    return 1; 
}

int queue_pop(){
    if(queue_isEmpty)
        return 0;
    int val = queue[front];
    front++;
    return val;
}

int queue_size(){
    return (rear - front);
}

int checkAll(){
    for(int row = 0; row < box_H; row++){
        for(int col = 0; col < box_W; col++){
            if(box[row][col] == 0)
                return -1;
        }
    }
    return 0;
}


int main(){
    int box_W, box_H;
    int box[1000][1000];
    
    // input
    scanf("%d %d", &box_W, &box_H);
    for(int row  = 0; row < box_H; row++){
        for(int col = 0; col < box_W; col++){
            scanf("%d", &box[row][col]);
        }
    }
    
    // find start point
    queue_init();
    for(int row = 0; row < box_H; row++){
        for(int col = 0; col < box_W; col++){
            if(box[row][col] == 1)
                queue_push((row * box_W) + col) // push node, not location
        }
    }

    // start BFS
    while(queue_size()){
        int prevSize = queue_size();
        for(int i = 0; i < prevSize; i++){
            int cur = queue_pop();
            int cur_row = cur / box_W;
            int cur_col = cur % box_W;
            if(box[cur_row-1][cur_col] == 0){
                box[cur_row-1][cur_col] == 1;
                queue_push((cur_row-1) * box_W + cur_col);
            }
            if(box[cur_row][cur_col+1] == 0){
                box[cur_row][cur_col+1] == 1;
                queue_push((cur_row) * box_W + cur_col+1);
            }
            if(box[cur_row+1][cur_col] == 0){
                box[cur_row+1][cur_col] == 1;
                queue_push((cur_row+1) * box_W + cur_col);
            }
            if(box[cur_row][cur_col-1] == 0){
                box[cur_row][cur_col-1] == 1;
                queue_push((cur_row) * box_W + cur_col-1);
            }      
        }
        if(queue_size() != 0)
            countDay += 1;
    }

    if(checkAll() == -1)
        printf("-1\n");
    else if(checkAll() == 0)
        printf("%d\n", countDay);

    return 0;
}