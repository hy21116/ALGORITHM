#include <stdio.h>

int N, L;
int Result = 0;
int map[100][100];


int main(){
    // initialize map
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++)
            map[i][j] = 0;
    }

    // input
    scanf("%d %d", &N, &L);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    }

    // check each row
    for(int row = 0; row < N; row++){
        int len = 0;
        bool checked[N]; // maybe need initialization?
        for(int col = 0; col < N; col++){
            if(map[row][col] == map[row][col+1])
                len += 1;
            else{
                if(map[row][col] > map[row][col+1]){  // downside
                    if(map[row][col] - map[row][col+1] != 1)
                        break;
                    else{
                        int count = 0;
                        int tmp = col + 1;
                        while(map[row][tmp] == map[row][col+1]){
                            count += 1;
                            tmp += 1;
                        }
                        if(count >= L){
                            len += 1;
                            for(int i = col+1; i < col+1+L; i++)
                                checked[i] = true;
                        }
                        else
                            break;
                    }
                }
                else{  // upside
                    if(map[row][col+1] - map[row][col] != 1)
                        break;
                    else{
                        int count = 0;
                        int tmp = col;
                        while(map[row][tmp] == map[row][col]){
                            if(checked[tmp] == false){
                                count += 1;
                                tmp -= 1;
                            }
                            break;
                        }
                        if(cont >= L){
                            len += 1;
                            for(int i = col; i > col-L; i--)
                                checkd[i] = true;
                        }
                        else
                        break;
                    }
                }
            } 
        }
        if(len == N)
            Result += 1;
    }

    return 0;
}