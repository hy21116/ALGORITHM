#include <stdio.h>

int N, brokenNum, digitNum;
int broken[10];
int digit[6];

int pow(int x, int y){
	int value = 1;
	for (int i = 0; i < y; i++)
		value = value * x;
	return value;
}

int abs(int x, int y){
	if (x >= y)
		return (x - y);
	else
		return (y - x);
}

int getDigitNum(int x){
	int tenNum = 5;
	while (x % pow(10, tenNum) == x){
		tenNum--;
		if (tenNum == 0) break;
	}
	return (tenNum + 1);
}

void getDigits(int x){
	int digitNum = getDigitNum(x);
	int tmp = digitNum - 1;
	for (int j = 0; j <= digitNum; j++){
		digit[j] = x / pow(10, tmp);
		x = x % pow(10, tmp);
		tmp--;
	}
}

int checkBroken(int x){
	int digitNum = getDigitNum(x);
	for (int i = 0; i < digitNum; i++){
		for (int j = 0; j < brokenNum; j++){
			if (digit[i] == broken[j]) return 1;
		}
	}
	return 0;
}


int main(){
	scanf("%d", &N);
	scanf("%d", &brokenNum);
	for (int i = 0; i < brokenNum; i++)
		scanf("%d", &broken[i]);

	int result, tempNum; 
	int diff = 500000; 
	
	if (brokenNum == 10){
		result = abs(N, 100);
	}
	if (brokenNum == 0){
		result = getDigitNum(N);
	}
	else{
		if (N != 100){
			for (tempNum = 0;; tempNum++){
				// initialize digit array
				for (int i = 0; i < 6; i++)
					digit[i] = 0;
				getDigits(tempNum);
				if (checkBroken(tempNum) == 1) continue;  // if tempNum has a broken button, go to the next case.
				if (diff >= abs(N, tempNum))
					diff = abs(N, tempNum);
				else if (diff < abs(N, tempNum)) break;
			}
			if (checkBroken((N - diff)) == 1){
				result = getDigitNum(N + diff) + diff;
			}
			else
				result = getDigitNum(N - diff) + diff;
		}
		else{  //  case : N(channel) = 100  (to reduce the time)
			result = 0;
		}
	}

	// Compare the case.
	// Using only (+) & (-) buttons can be smaller.
	if (result > abs(N, 100))
		printf("%d\n", abs(N, 100));
	else
		printf("%d\n", result);
}