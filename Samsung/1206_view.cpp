#include <stdio.h>

int X;
int map[1000];

int main(){
	int test_case;
	for (test_case = 1; test_case <= 10; test_case++){
		scanf("%d", &X);
		for (int i = 0; i < X; i++)
			scanf("%d", &map[i]);

		int result = 0;
		for (int i = 2; i < X - 2; i++){
			bool flag = true;
			for (int j = i - 2; j <= i + 2; j++){
				if (map[j] > map[i]){
					flag = false;
					break;
				}
			}
			if (flag == false)
				continue;
			else{
				int min = 255;
				for (int j = i - 2; j <= i + 2; j++){
					if (j != i){
						if (map[i] - map[j] < min)
							min = map[i] - map[j];
					}
				}
				
				result += min;
				i += 2;
			}
		}

		printf("#%d %d\n", test_case, result);
	}

	return 0;
}