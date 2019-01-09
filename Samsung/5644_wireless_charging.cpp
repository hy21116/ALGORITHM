#include <stdio.h>
 
#define MAX 101
 
typedef struct data{
    int y;
    int x;
    int c;
    int p;
}Data;
 
int mapA[MAX];
int mapB[MAX];
int checkA[8];
int checkB[8];
Data BC[8];
int dirY[5] = {0, -1, 0, 1, 0};
int dirX[5] = {0, 0, 1, 0, -1};
 
int distance(int curY, int BCY, int curX, int BCX){
    int dY, dX, d;
    if (curY > BCY)
        dY = curY - BCY;
    else
        dY = BCY - curY;
    if (curX > BCX)
        dX = curX - BCX;
    else
        dX = BCX - curX;
 
    d = dY + dX;
    return d;
}
 
int main(){
    int T;
 
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++){
        // input
        int M, A;
        scanf("%d %d", &M, &A);
        for (int i = 1; i <= M; i++)
            scanf("%d", &mapA[i]);
        for (int i = 1; i <= M; i++)
            scanf("%d", &mapB[i]);
        for (int i = 0; i < A; i++)
            scanf("%d %d %d %d", &BC[i].x, &BC[i].y, &BC[i].c, &BC[i].p);
 
 
        int curYA = 0;
        int curXA = 0;
        int curYB = 9;
        int curXB = 9;
        int result = 0;
        for (int t = 0; t <= M; t++){
            // intialize
            for (int i = 0; i < 8; i++)
                checkA[i] = checkB[i] = 0;
 
            // calculate distance
            int idxA = 0;
            int idxB = 0;
            for (int i = 0; i < A; i++){
                int BCY = BC[i].y - 1;
                int BCX = BC[i].x - 1;
                int BCC = BC[i].c;
                int dA = distance(curYA, BCY, curXA, BCX);
                int dB = distance(curYB, BCY, curXB, BCX);
                if (dA <= BCC){
                    checkA[idxA] = i + 1;
                    idxA++;
                }
                if (dB <= BCC){
                    checkB[idxB] = i + 1;
                    idxB++;
                }
            }
            curYA += dirY[mapA[t+1]];
            curXA += dirX[mapA[t+1]];
            curYB += dirY[mapB[t+1]];
            curXB += dirX[mapB[t+1]];

            // find max value cosidering all cases
            int score = 0;
            if (checkA[0] == 0 || checkB[0] == 0){
                if (checkA[0] == 0 && checkB[0] == 0)
                    score = 0;
                else if (checkA[0] == 0 && checkB[0] != 0){
                    int idx = 0;
                    while (checkB[idx]){
                        int temp = BC[checkB[idx] - 1].p;
                        if (temp > score)
                            score = temp;
                        idx++;
                    }
                }
                else if (checkB[0] == 0 && checkA[0] != 0){
                    int idx = 0;
                    while (checkA[idx]){
                        int temp = BC[checkA[idx] - 1].p;
                        if (temp > score)
                            score = temp;
                        idx++;
                    }
                }
            }
            else{
                int idx_A = 0;
                int idx_B = 0;
                while (checkA[idx_A]){
                    while (checkB[idx_B]){
                        //printf("A : %d, B : %d\n", checkA[idx_A], checkB[idx_B]);
                        int temp;
                        if (checkA[idx_A] == checkB[idx_B])
                            temp = BC[checkA[idx_A] - 1].p;
                        else
                            temp = BC[checkA[idx_A] - 1].p + BC[checkB[idx_B] - 1].p;
                        if (temp > score)
                            score = temp;
                        idx_B++;
                    }
                    idx_A++;
                    idx_B = 0;
                }
            }
            result += score;
        }
         
        printf("#%d %d\n", test_case, result);
    }
 
    return 0;
}