
#include <stdio.h>

//#include <fstream>



int cnt0;
int cnt1;
void fibonacci(int n, int* cnt0, int* cnt1);
int main() {
	int N;
	int arr[1000];
	FILE * fp = fopen("d:\\data\\input.txt", "r");
	scanf("%d", &N);

	int cnt0[1000], cnt1[1000];
	int res1, res2;
	for (int i = 0; i < N; i++) {
		scanf("%d\n", &arr[i]);
		fibonacci(arr[i],cnt0,cnt1);
		printf("%d %d\n", cnt0[arr[i]], cnt1[arr[i]]);
	//	cout << cnt0 << " " << cnt1 << endl;


	}

	return 0;
}

void fibonacci(int n, int* cnt0, int* cnt1) {

	cnt0[0] = 1;
	cnt1[0] = 0;
	cnt0[1] = 0;
	cnt1[1] = 1;


	for (int i = 2; i <= n; i++) {
		cnt0[i] = cnt0[i - 2] + cnt0[i - 1];
		cnt1[i] = cnt1[i - 2] + cnt1[i - 1];
	}



//	if (n == 0) {
////		printf("0");
//		cnt0++;
//		return 0;
//	}
//	else if (n == 1) {
////		printf("1");
//		cnt1++;
//		return 1;
//	}
//	else {
//		return fibonacci(n-1) + fibonacci(n-2);
//	}
}