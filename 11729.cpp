#include <iostream>
#include <stdio.h>
using namespace std;


int hanoiCnt(int n);
void hanoi(int prev, int to, int next, int size);
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int num;
	scanf("%d",&num);
	int res = hanoiCnt(num);
	cout << res << endl;
	hanoi(1, 2, 3, num);
}

void hanoi(int prev, int to, int next, int size) {

	if (size == 1) {
		printf("%d %d\n", prev, next);
		
	}
	else {
		hanoi(prev, next, to, size - 1);
		printf("%d %d\n", prev, next);
		hanoi(to, prev, next, size - 1);
	}
}
int hanoiCnt(int n) {
	if (n == 0) return 0;

	return 2 * hanoiCnt(n - 1) + 1;
}