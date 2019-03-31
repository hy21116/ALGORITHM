#include <string>
#include <vector>

using namespace std;

typedef struct data{
	bool flag;
	int count;
}Data;

Data info[100000];
char stack[100000];
int top, sum;

int solution(string arrangement) {  
    int answer = 0;
    
    int tempLen = 0;
	while (arrangement[tempLen++]){}
	//printf("%d\n", tempLen - 1);

	for (int i = 0; i < tempLen; i++){
		if (arrangement[i] == '('){
			if (top != 0)
				info[top - 1].flag = true;
			stack[top++] = arrangement[i];
		}
		else{
			top--;
			//if (top != 0){
			if (info[top].flag == true){
				sum = sum + info[top].count + 1;
				info[top].flag = false;
				info[top].count = 0;
			}
			else{
				for (int j = top - 1; j >= 0; j--){
					info[j].count += 1;
				}
			}
			//}	
		}
	}
    answer = sum;
    
    return answer;
}