#include <stdio.h>

#define MAX 100

char src[] = {0, 97, 98, 99, 100, 101};
int N, R;
int visited[MAX];
int arr[MAX];
int count;

void print_comb(){
    printf("[");
    for(int i = 1; i <= R; i++)
        printf("%c", arr[i]);
    puts("]");
}

void comb(int n ,int r){
    if(r == 0){
        count++;
        print_comb();
        return;
    }
    if(n < r)
        return;
    
    arr[r] = src[n];
    comb(n-1, r-1);
    comb(n-1, r);
}

// ref : get the count of combination cases
int getCnt_comb(int n, int r){
    if(r == 0 || n == r)
        return 1;
    
    return getCnt_comb(n-1, r-1) + getCnt_comb(n-1, r);
}


int main(){
 
    N = 5;
    R = 3;

    comb(N, R);
    printf("count : %d\n", count);
    printf("count_using getCnt : %d\n", getCnt_comb(N, R));

    return 0;
}