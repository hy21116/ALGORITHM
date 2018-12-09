#include <stdio.h>

#define MAX 100

char src[] = {0, 97, 98, 99, 100, 101};
int arr[MAX];
int N;
int count;

void print_subset(){
    printf("[");
    for(int i = 1; i <= N; i++){
        if(arr[i])
            printf("%c", src[i]);
    }
    puts("]");
}

void subset(int step){
    if(step == N){
        count++;
        print_subset();
        return;
    }

    step++;
    // only use '0' and '1' : yes or no
    for(int i = 0; i < 2; i++){
        arr[step] = i;
        subset(step);
    }
}

int main(){

    N = 3;
    subset(0);

    return 0;
}