#include <stdio.h>
#include <iostream>

#define MAX 100

char tempArr[MAX][MAX];
char Arr[MAX][MAX];
int visited[MAX][MAX];
// right, down, left, up
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int result;

int dfs(int y, int x){
    //printf("(%d, %d)\n", y, x);
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        if(Arr[y+dy[i]][x+dx[i]] == 3){
            //puts("finish!");
            result = 1;
        }
        if(visited[y+dy[i]][x+dx[i]] == 0 && Arr[y+dy[i]][x+dx[i]] == 0)
            dfs(y+dy[i], x+dx[i]);
    }
}


int main(){
    int T = 10;
    
    freopen("input.txt","r", stdin);

    for(int test_case = 1; test_case <= T; test_case++){
        // initialize
        result = 0;
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++)
                visited[i][j] = 0;
        }
        
        // get input
        scanf("%d", &test_case);
        for(int i = 0; i < MAX; i++){
            scanf("%s", tempArr[i]);
        }

        // convert 'char' to 'int'
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++)
                Arr[i][j] = tempArr[i][j] - 48;
        }

        dfs(1, 1);

        printf("#%d %d\n", test_case, result);
    }

    return 0;
}