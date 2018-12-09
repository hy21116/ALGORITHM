#include <stdio.h>

#define MAX 100

char src[] = {0, 97, 98, 99, 100, 101};
int N, R;
int count;
int arr[MAX];
int visited[MAX];

void print_perm(){
    printf("[");
    for(int i = 1; i <= R; i++){
        printf("%c", src[arr[i]]);
    }
    puts("]");
}

void btr_perm(int step){
    if(step == R){
        count++;
        print_perm();
        return;
    }

    step++;
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            visited[i] = 1;
            arr[step] = i;
            btr_perm(step);
            visited[i] = 0;
        }
    }
}

// ref : get the count of permutation cases
int getCnt_perm(int n, int r){
    int result = 1;
    for(int i = n; i > n-r; i--)
        result *= i;
    return result;
}


int main(){
    
    N = 3;
    R = 2;

    btr_perm(0);
    printf("count : %d\n", count);
    printf("count_using getCnt : %d\n", getCnt_perm(N, R));

    return 0;
}