#include <stdio.h>

int N, brokenNum;
bool broken[10];

// check if is is possible to move the channel using only number buttons.
// if it is possible : 1, if it is not possible : 0
int checkNumButton(int channel){
	if (channel == 0){
		if (broken[0])
			return 0;
		return 1;
	}
	int digitNum = 0;
	while (channel > 0){
		if (broken[channel % 10])
			return 0;
		digitNum += 1;
		channel /= 10;
	}
	return digitNum;
}

int abs(int x){
	if (x >= 0)
		return x;
	else
		return -x;
}

int main(){
	scanf("%d", &N);
	scanf("%d", &brokenNum);
	for (int i = 0; i < brokenNum; i++){
		int tmp;
		scanf("%d", &tmp);
		broken[tmp] = true;
	}
	int diff = abs(N - 100); // only using (+), (-) buttons
	for (int i = 0; i <= 1000000; i++){
		int result = checkNumButton(i);
		if (result > 0){ // if non-possible, then continue.
			int press = abs(i - N);
			/*int press = i - N;
			if (press < 0){
				press = -press;
			}*/
			if (diff > result + press)
				diff = result + press;
		}
	}
	printf("%d\n", diff);
	return 0;
}