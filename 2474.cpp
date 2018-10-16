#include <iostream>
using namespace std;


int Fibo(int n, int *);
int main() {
	
	int n;
	int arr[45];
	cin >> n;
	
	int res = Fibo(n, arr);
	cout << res;
	

	return 0;
}

int Fibo(int n, int* arr) {

	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	return arr[n];
}