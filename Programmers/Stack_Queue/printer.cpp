#include <string>
#include <vector>

using namespace std;

int queue[1000];
int temp[1000];
int front, rear, len;

bool checkRun(int curVal, int* entire){
	for (int i = front; i < rear; i++){
		if (curVal < entire[i])
			return true;
	}
	return false;
}

int solution(vector<int> priorities, int location) {
	int answer = 0;
	////////////////////////////////////////////////////////////////////////////
	while (priorities[len] > 0 && priorities[len] < 10){ len++; }

	for (int i = 0; i < len; i++){
		temp[i] = priorities[i];
		queue[i] = i;
	}

	int tempVal1 = 0; int tempVal2 = 0; rear = len;
	while (1){
		while (checkRun(temp[queue[front]], temp)){
			tempVal1 = queue[front];
			tempVal2 = temp[front];
			front++;
			queue[rear] = tempVal1;
			temp[rear] = tempVal2;
			rear++;
		}
		if (queue[front] == location)
			break;
		else
			front++;
			answer++;
	}
	///////////////////////////////////////////////////////////////////////////
	return answer + 1;
}