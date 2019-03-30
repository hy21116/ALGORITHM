#include <stdio.h>
 
int stack[10000];
int top;

int main(){
	int N;
	scanf("%d", &N);

	char command[5];
	char start;
	for (int i = 0; i < N; i++){
		scanf("%s", &command);
		//printf("%c", command[0]);
		start = command[0];
		if (start == 'p'){
			if (command[1] == 'u'){
				int val;
				scanf("%d", &val);
				stack[top++] = val;
			}
			else{
				if (top == 0)
					printf("%d\n", -1);
				else
					printf("%d\n", stack[--top]);
			}
		}
		else if (start == 't'){
			if (top == 0)
				printf("%d\n", -1);
			else
				printf("%d\n", stack[top - 1]);
		}
		else if (start == 's'){
			printf("%d\n", top);
		}
		else if (start == 'e'){
			printf("%d\n", bool(top == 0));
		}
	}
	
	return 0;
}