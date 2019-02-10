#include <stdio.h>

int input[1000];
int score[1000];

int main(){
	int T, test_case;
	
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++){
		scanf("%d", &test_case);
		for (int i = 0; i < 1000; i++){
			scanf("%d", &input[i]);
			score[i] = 0;
		}

		for (int i = 0; i < 1000; i++)
			score[input[i]]++;

		int max = 0;
		for (int i = 0; i < 1000; i++){
			if (score[i] > max)
				max = score[i];
		}

		int result;
		for (int i = 0; i < 1000; i++){
			if (score[i] == max)
				result = i;
		}

		printf("#%d %d\n", test_case, result);
	}

	return 0;
}