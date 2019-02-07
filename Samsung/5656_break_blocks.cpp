#include <stdio.h>
 
typedef struct data{
    int val;
    int y;
    int x;
}Data;
 
int N, W, H, idx, front, rear;
int map[15][12];
int temp[15][12];
int start[20736][4];
int arr[5];
Data queue[200];
 
void startArray(int step){
    if (step == N){
        for (int i = 1; i <= N; i++){
            start[idx][i - 1] = arr[i];
        }
        idx++;
        return;
    }
 
    step++;
    for (int i = 0; i < W; i++){
        arr[step] = i;
        startArray(step);
    }
}
 
int main(){
    int T, test_case;
 
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++){
        scanf("%d %d %d", &N, &W, &H);
        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                scanf("%d", &map[i][j]);
            }
        }

        idx = 0;
        startArray(0);
        
        int min = H * W;
        for (int k = 0; k < idx; k++){
            // copy map
            for (int i = 0; i < H; i++){
                for (int j = 0; j < W; j++){
                    temp[i][j] = map[i][j];
                }
            }

            for (int i = 0; i < N; i++){
                int curX = start[k][i];
                int curY = 0;
                while (temp[curY][curX] == 0 && curY < H){
                    curY++;
                }
                int curVal = temp[curY][curX];
                front = rear = 0;
                if (curVal != 0){
                    queue[rear].x = curX;
                    queue[rear].y = curY;
                    queue[rear].val = curVal;
                    rear++;
                    temp[curY][curX] = 0;
                }
                while (rear - front != 0){
                    curX = queue[front].x;
                    curY = queue[front].y;
                    curVal = queue[front].val;
                    front++;
                    if (curVal > 1){
                        for (int m = -curVal + 1; m <= curVal - 1; m++){
                            if (curY + m >= 0 && curY + m < H){
                                int tempVal = temp[curY + m][curX];
                                if (tempVal != 0){
                                    if (tempVal > 1){
                                        queue[rear].x = curX;
                                        queue[rear].y = curY + m;
                                        queue[rear].val = tempVal;
                                        rear++;
                                    }
                                    temp[curY + m][curX] = 0;
                                }
                            }
                            if (curX + m >= 0 && curX + m < W){
                                int tempVal = temp[curY][curX + m];
                                if (tempVal != 0){
                                    if (tempVal > 1){
                                        queue[rear].x = curX + m;
                                        queue[rear].y = curY;
                                        queue[rear].val = tempVal;
                                        rear++;
                                    }
                                    temp[curY][curX + m] = 0;
                                }
                            }
                        }
                    }
                }

                // rearrange
                for (int j = 0; j < W; j++){
                    int point = H - 1;
                    for (int m = H - 1; m >= 0; m--){
                        if (temp[m][j] != 0){
                            temp[point][j] = temp[m][j];
                            if (point != m)
                                temp[m][j] = 0;
                            point--;
                        }
                    }
                }
            }

            // count num
            int count = 0;
            for (int i = 0; i < H; i++){
                for (int j = 0; j < W; j++){
                    if (temp[i][j] != 0)
                        count++;
                }
            }

            if (count < min)
                min = count;
            if (min == 0)
                break;
        }
        printf("#%d %d\n", test_case, min);
    }
    return 0;
}