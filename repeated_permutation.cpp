#include <stdio.h>

#define MAX 100

char src[] = {0, 97, 98, 99, 100, 101};
int N, R;
int arr[MAX];
int count;

void print_perm(){
    printf("[");
    for(int i = 1; i <= R; i++)
        printf("%c", src[arr[i]]);
    puts("]");
}

void repeated_perm(int step){
    if(step == R){
        count++;
        print_perm();
        return;
    }

    step++;
    for(int i = 1; i <= N; i++){
        arr[step] = i;
        repeated_perm(step);
    }
}


int main(){

    N = 3;
    R = 2;

    repeated_perm(0);
    printf("count : %d\n", count);

    return 0;
}