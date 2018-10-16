#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

void sqrtSum(int, int*);
int sqrtSum2(int, int*);
int main() {

	int n;
	cin >> n;
	int arr[100000] = { 0, };

	for (int i = 1; i < 100000; i++) { // arr[1] ~ arr[n-1]���� ���� ���ϴ� �κ�
		sqrtSum(i, arr);
		//		cout << "arr["<<i<<"]: " <<arr[i] << endl;
	}

	int res = sqrtSum2(n, arr);
	cout << res;
	//	cout << "arr[" << n << "]: " << arr[n] << endl;

	return 0;
}

void sqrtSum(int n, int *arr) {

	int cnt;
	int leftAmt;
	int minCnt = 100000;
	int i;
	// i = sqrt(n) �־��� ���� ��Ʈ���� ������ ������ Ȱ��

	for (i = sqrt(n); i >= 1; i--) {   // ������ ������ ������ �ִ��� ����
		cnt = 0; //�ʱ�ȭ
		leftAmt = n;

		while (leftAmt >= 0) {
			if (cnt == 0) {
				cnt++;
				leftAmt -= i*i;
			}
			if (cnt >= 1) {
				cnt += arr[leftAmt];
				break;
			}
		}
		if (minCnt > cnt)
			minCnt = cnt;
	}

	arr[n] = minCnt;
	return;
}


int sqrtSum2(int n, int *arr) {

	int cnt;
	int leftAmt;
	int minCnt = 100000;
	int i;
	// i = sqrt(n) �־��� ���� ��Ʈ���� ������ ������ Ȱ��

	for (i = sqrt(n); i >= 1; i--) {   // ������ ������ ������ �ִ��� ����
		cnt = 0; //�ʱ�ȭ
		leftAmt = n;

		while (leftAmt >= 0) {
			if (cnt == 0) {
				cnt++;
				leftAmt -= i*i;
			}
			if (cnt >= 1) {
				cnt += arr[leftAmt];
				break;
			}
		}
		if (minCnt > cnt)
			minCnt = cnt;
	}
	return minCnt;
}
