#include <iostream>
#include <stdio.h>

#define MAX 28

using namespace std;

int N, K, result;
char num[MAX];
int decimal[50];

void quickSort(int s, int e){
	if (s < e){
		int p = s;
		int l = s;
		int r = e;
		while (1){
			while (decimal[p] >= decimal[l] && l<r){ l++; }
			while (decimal[p] < decimal[r]){ r--; }
			if (l < r){
				int t = decimal[l]; decimal[l] = decimal[r]; decimal[r] = t;
			}
			else{
				break;
			}
		}
		int t = decimal[p]; decimal[p] = decimal[r]; decimal[r] = t;
		quickSort(s, r - 1);
		quickSort(r + 1, e);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("sample_input.txt", "r", stdin);
	
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){
		// initialize
		for (int i = 0; i < 50; i++)
			decimal[i] = 0;

		// input
		scanf("%d %d ", &N, &K);
		scanf("%s", num);

		int rotate = N / 4;
		
		int idx = 0;
		for (int k = 0; k < rotate; k++){
			// convert to decimal 
			for (int i = 0; i < 4; i++){
				int val = 0;
				for (int j = 0; j < rotate; j++){
					int temp = 0;
					int index = i * rotate + j;
					if (num[index] >= 65)
						temp = num[index] - 55;
					else
						temp = num[index] - 48;
					val = val * 16;
					val += temp;
				}
				decimal[idx++] = val;
			}

			// shift array num
			char temp = num[N-1];
			for (int i = N - 2; i >= 0; i--){
				num[i + 1] = num[i];
			}
			num[0] = temp;
		}

		// sort decimal
		quickSort(0, N - 1);
		// if it has identical number, then delete
		int max = 987654321;
		int count = 1;
		for (int i = idx - 1; i >= 0; i--){
			if (count == K)
				result = decimal[i];
			if (max > decimal[i]){
				count++;
				max = decimal[i];
			}
		}

		printf("#%d %d\n", test_case ,result);
	}
	return 0;
}