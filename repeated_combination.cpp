#include <stdio.h>

#define MAX 100

char src[] = {0, 97, 98, 99, 100, 101};
int N, R;
int arr[MAX];
int count;

void print_comb(){
    printf("[");
    for(int i = 1; i <= R; i++)
        printf("%c", arr[i]);
    puts("]");
}

void repeated_comb(int n ,int r){
    if(r == 0){
        count++;
        print_comb();
        return;
    }
    if(n == 0)
        return;
    
    arr[r] = src[n];
    repeated_comb(n, r-1);
    repeated_comb(n-1, r);
}


int main(){
 
    N = 5;
    R = 3;

    repeated_comb(N, R);
    printf("count : %d\n", count);
    
    return 0;
}