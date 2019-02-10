#include <stdio.h>

int map[9][9];
int count[10];

void init(){
	for (int i = 0; i < 10; i++)
		count[i] = 0;
}

bool check(){
	for (int i = 0; i < 9; i++){
		init();
		for (int j = 0; j < 9; j++)
			count[map[i][j]]++;
		for (int i = 1; i < 10; i++){
			if (count[i] != 1)
				return false;
		}
	}

	for (int i = 0; i < 9; i++){
		init();
		for (int j = 0; j < 9; j++)
			count[map[j][i]]++;
		for (int j = 1; j < 10; j++){
			if (count[j] != 1)
				return false;
		}
	}

	for (int k = 0; k < 3; k++){
		init();
		for (int i = 3 * k; i < 3 * (k + 1); i++){
			for (int j = 0; j < 3; j++)
				count[map[i][j]]++;
		}
		for (int j = 1; j < 10; j++){
			if (count[j] != 1)
				return false;
		}

		init();
		for (int i = 3 * k; i < 3 * (k + 1); i++){
			for (int j = 3; j < 6; j++)
				count[map[i][j]]++;
		}
		for (int j = 1; j < 10; j++){
			if (count[j] != 1)
				return false;
		}

		init();
		for (int i = 3 * k; i < 3 * (k + 1); i++){
			for (int j = 6; j < 9; j++)
				count[map[i][j]]++;
		}
		for (int j = 1; j < 10; j++){
			if (count[j] != 1)
				return false;
		}
	}
	
	return true;
}

int main(){
	int T, test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++)
				scanf("%d", &map[i][j]);
		}

		printf("#%d %d\n", test_case, check());
	}
}