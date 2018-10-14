#include <stdio.h>

int E, S, M;
int e, s, m, date;

int main(){
	e = s = m = 1;
	scanf("%d %d %d", &E, &S, &M);

	for (date = 1;; date++){
		if (e == E && s == S && m == M) break;
		e++; s++; m++;
		if (e == 16) e = 1;
		if (s == 29) s = 1;
		if (m == 20) m = 1;
	}
	printf("%d", date);

	return 0;
}