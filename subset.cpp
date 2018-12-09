#include <stdio.h>

#define MAX 100

char src[] = {0, 97, 98, 99, 100, 101};
int src2[] = {0, 1, 2, 3, 4, 5};
int arr[MAX];
int N;
int count;
int key;

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

void print_subset2(){
    printf("[");
    for(int i = 1; i <= N; i++){
        if(arr[i])
            printf("%d", src2[i]);
    }
    puts("]");
}

// if you want some specific subsets
// for example : the sum of all components should be smaller than 10
void subset_cond(int step, int sum){
    if(sum > key)
        return;
    if(step == N){
        count++;
        print_subset2();
        return;
    }

    step++;
    // only use '0' and '1' : yes or no
    arr[step] = 0;
    subset_cond(step, sum);
    arr[step] = 1;
    subset_cond(step, sum+src2[step]);
}


int main(){

    N = 3;
    subset(0);

    key = 5;
    subset_cond(0, 0);

    return 0;
}