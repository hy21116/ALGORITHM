#include <stdio.h>
 
#define MAX 21
 
int N, X;
int map[MAX][MAX];
int result;
int checked[MAX];
int resultFlag = 1;
 
int main(){
    int T;
 
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++){
        // initialize
        result = 0;
        for (int i = 0; i < MAX; i++)
            checked[i] = 0;
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++)
                map[i][j] = 0;
        }
 
 
        // input
        scanf("%d %d", &N, &X);
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                scanf("%d", &map[i][j]);
            }
        }
 
        // check row
        for (int row = 0; row < N; row++){
            resultFlag = 1;
            for (int i = 0; i < N; i++)
                checked[i] = 0;
 
            for (int col = 0; col < N - 1; col++){
                int diff = 0;
                int flag = 0;
                if (map[row][col] < map[row][col + 1]){// upside (flag : 0) - need checked
                    diff = map[row][col + 1] - map[row][col];
                     
                }
                else{ // downside (flag : 1)
                    diff = map[row][col] - map[row][col + 1];
                    flag = 1;
                }
 
                if (diff > 1){
                    resultFlag = 0;
                    break;
                }
                else if (diff == 0)
                    continue;
                else if(diff == 1){
                    int subCnt = 0;
                    if (flag){ // downside
                        for (int i = 0; i < X; i++){
                            if (col + 1 + i == N)
                                break;
                            if (map[row][col + 1 + i] == map[row][col + 1])
                                subCnt++;
                            else
                                break;
                        }
                        if (subCnt == X){
                            for (int i = 0; i < X; i++)
                                checked[col + 1 + i] = 1;
                            col += X - 1;
                        }
                        else{
                            resultFlag = 0;
                            break;
                        }
                             
                    }
                    else{ // upside
                        for (int i = 0; i < X; i++){
                            if (col - i == -1)
                                break;
                            if (map[row][col - i] == map[row][col] && !checked[col - i])
                                subCnt++;
                            else
                                break;
                        }
                        if (subCnt == X){
                            for (int i = 0; i < X; i++)
                                checked[col - i] = 1;
                        }
                        else{
                            resultFlag = 0;
                            break;
                        }
 
                    }
                }
 
            }
            if (resultFlag)
                result++;
        }
 
        // check col
        for (int col = 0; col < N; col++){
            resultFlag = 1;
            for (int i = 0; i < N; i++)
                checked[i] = 0;
 
            for (int row = 0; row < N - 1; row++){
                int diff = 0;
                int flag = 0;
                if (map[row][col] < map[row + 1][col]){// upside (flag : 0) - need checked
                    diff = map[row + 1][col] - map[row][col];
 
                }
                else{ // downside (flag : 1)
                    diff = map[row][col] - map[row + 1][col];
                    flag = 1;
                }
 
                if (diff > 1){
                    resultFlag = 0;
                    break;
                }
                else if (diff == 0)
                    continue;
                else if (diff == 1){
                    int subCnt = 0;
                    if (flag){ // downside
                        for (int i = 0; i < X; i++){
                            if (row + 1 + i == N)
                                break;
                            if (map[row + 1 + i][col] == map[row + 1][col])
                                subCnt++;
                            else
                                break;
                        }
                        if (subCnt == X){
                            for (int i = 0; i < X; i++)
                                checked[row + 1 + i] = 1;
                            row += X - 1;
                        }
                        else{
                            resultFlag = 0;
                            break;
                        }
 
                    }
                    else{ // upside
                        for (int i = 0; i < X; i++){
                            if (row - i == -1)
                                break;
                            if (map[row - i][col] == map[row][col] && !checked[row - i])
                                subCnt++;
                            else
                                break;
                        }
                        if (subCnt == X){
                            for (int i = 0; i < X; i++)
                                checked[row - i] = 1;
                        }
                        else{
                            resultFlag = 0;
                            break;
                        }
 
                    }
                }
 
            }
            if (resultFlag)
                result++;
        }
 
        printf("#%d %d\n", test_case, result);
    }
 
 
    return 0;
}