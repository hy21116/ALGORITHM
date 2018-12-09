#include <stdio.h>

char src[] = {97, 98, 99};
int N = 3;
// As 'R' increases, 'for' must need to increase.
// int R = 2;

int main(){

    // combination
    puts("combination");
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(i != j)
                printf("(%c %c)\n", src[i], src[j]); 
        }
    }

    // combination - reduce operations
    // can delete 'if'
    puts("combination - reduce operations");
    for(int i = 0; i < N-1; i++){
        for(int j = i + 1; j < N; j++){
            printf("(%c %c)\n", src[i], src[j]); 
        }
    }

    // repeated combination
    puts("repeated combination");
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            printf("(%c %c)\n", src[i], src[j]); 
        }
    }

    return 0;
}