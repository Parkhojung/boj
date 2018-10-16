#include <iostream>
using namespace std;

void nonDescending(int(*arr)[1001], int n);
int main() {
	int N;
	int i, j;
	
	int arr[10][1001] = { 0 };
	int res;

	cin >> N;
	for (i = 0; i < 10; i++) {
		arr[i][1] = 1;
	}
	
	for (j = 2; j <= N; j++) {
		nonDescending(arr, j);
	}
	
	for (i =0 ; i < 4; i++) {
		for (j = 0; j < 10; j++) {
			printf("arr[%d][%d]: %d\n", i, j, arr[j][i]);
		}
		cout << endl;
	}

	//for (j = 0; j < 10; j++) {
	//	printf("arr[%d][%d]: %d\n", i, N, arr[j][N]);
	//}
	//cout << endl;

	res = 0;
	for(i = 0 ; i<10; i++){
		res += arr[i][N]%10007;
	}
	res = res % 10007;
	cout << res;
	return 0;
}

void nonDescending(int (*arr)[1001], int n) {
	int i, j;
	for (i = 0; i < 10; i++) { // 현대 계단
		for (j = 0; j <= i; j++) { // 현재 계단을 기준으로 그것보다 높지 않은 계단
			arr[i][n] += arr[j][n-1]%10007;
		}
	}
}