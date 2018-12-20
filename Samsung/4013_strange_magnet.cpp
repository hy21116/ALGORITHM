#include <stdio.h>
 
int map[4][8];
int direction[4];
int flag[3];
 
void move(int dir, int arr[]){
    if (dir == 1){
        int temp = arr[7];
        for (int i = 7; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
    else if (dir == -1){
        int temp = arr[0];
        for (int i = 0; i < 7; i++){
            arr[i] = arr[i + 1];
        }
        arr[7] = temp;
    }
    else
        return;
}
 
 
int main(){
    int T, K;
 
    //freopen("sample_input.txt", "r", stdin);
 
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++){
        // input
        scanf("%d", &K);
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 8; j++){
                scanf("%d", &map[i][j]);
            }
        }
 
        for (int i = 0; i < K; i++){
            int start, dir;
            scanf("%d %d", &start, &dir);
            // flag
            for (int i = 0; i < 3; i++){
                if (map[i][2] != map[i + 1][6])
                    flag[i] = 1;
            }

            int count = 0;
            for (int i = 0; i < 3; i++){
                if (flag[i] == 1)
                    count++;
            }
 
            int idx = start - 1;
            switch (count){
            case(0) :
                direction[idx] = dir;
                break;
            case(1) :
                direction[idx] = dir;
                if (flag[0] == 1){
                    if (idx == 0 || idx == 1)
                        direction[!idx] = -dir;
                }
                else if (flag[1] == 1){
                    if (idx == 1)
                        direction[2] = -dir;
                    else if (idx == 2)
                        direction[1] = -dir;
                }
                else{
                    if (idx == 2)
                        direction[3] = -dir;
                    else if (idx == 3)
                        direction[2] = -dir;
                }
                break;
            case(2) :
                // special case
                if (flag[0] == 1 && flag[1] == 0 && flag[2] == 1){
                    if (idx == 0 || idx == 1){
                        direction[idx] = dir;
                        direction[!idx] = -dir;
                        //direction[(idx + 1) % 2] = -dir;
                    }
                    else{
                        direction[idx] = dir;
                        direction[(!(idx % 2)) + 2] = -dir;
                    }
                }
                else{
                    direction[idx] = dir;
                    if (flag[0] == 1 && flag[1] == 1 && flag[2] == 0){
                        if (idx != 3){
                            direction[(idx + 2) % 4] = dir;
                            for (int i = 0; i < 4; i++){
                                if (direction[i] == 0)
                                    direction[i] = -dir;
                            }
                            direction[3] = 0;
                        }
                    }
                    else if (flag[0] == 0 && flag[1] == 1 && flag[2] == 1){
                        if (idx != 0){
                            direction[(idx + 2) % 4] = dir;
                            for (int i = 0; i < 4; i++){
                                if (direction[i] == 0)
                                    direction[i] = -dir;
                            }
                            direction[0] = 0;
                        }
                    }
                }
                break;
            case(3) :
                direction[idx] = direction[(idx + 2) % 4] = dir;
                for (int i = 0; i < 4; i++){
                    if (direction[i] == 0)
                        direction[i] = -dir;
                }
                break;
            }
            // move
            for (int i = 0; i < 4; i++){
                move(direction[i], map[i]);
            }
            // initialize
            for (int i = 0; i < 3; i++){
                flag[i] = 0;
                direction[i] = 0;
            }
            direction[3] = 0;
        }
 
        // score
        int score = 0;
        for (int i = 0; i < 4; i++){
            if (map[i][0] == 0)
                continue;
            else{
                int pow = 1;
                for (int j = 0; j < i; j++)
                    pow *= 2;
                score += pow;
            } 
        }
        printf("#%d %d\n", test_case, score);
    }
 
    return 0;
}
