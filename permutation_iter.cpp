#include <stdio.h>

char src[] = {97, 98, 99};
int N;
// As 'R' increases, 'for' must need to increase.
// int R = 2;


int main(){
    
    // permuatation
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != j)
                printf("(%c, %c)\n", src[i], src[j]);
        }
    }
    
    // repeated permutation
    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 3; j++){
            printf("(%c, %c)\n", src[i], src[j]);
        }
    }

    return 0;
}