#include <iostream>
#include <malloc.h>
#include <fstream>
#include <algorithm>
using namespace std;

typedef int keytype;

void mergesort(int n, keytype *S);
void merge(int h, int m, const keytype* U, const keytype *V, keytype* S);
int main() {
	
	fstream fin("d:\\data\\input.txt");
	int cnt, index,i;
	cin >> cnt >> index;
	keytype *arr = (keytype*)malloc(sizeof(keytype)*(cnt + 1));
	for (i = 1; i < cnt; i++) {
		cin >> arr[i];
	}

//	arr = 0;
//	sort(arr, arr +1);
	mergesort(cnt, arr);
	cout << arr[index+1];

	return 0;
}

void mergesort(int n, keytype *S) {
	if (n > 1) {
		const int h = n / 2, m = n - h;
		keytype *U = (keytype*)malloc(sizeof(keytype)*(h+1));
		keytype *V = (keytype*)malloc(sizeof(keytype)*(m+1));
	
		for (int i = 1; i <= h; i++) {
			U[i] = S[i];
		}
		for (int i = 1; i <= m; i++) {
			V[i] = S[i+h];
		}
		mergesort(h, U);
		mergesort(m, V);
		merge(h, m, U, V, S);
	}
}

void merge(int h, int m, const keytype* U, const keytype *V, keytype* S) {
	int i, j, k;
	i = 1; j = 1; k = 1;
	while (i <= h && j <= m) {
		if (U[i] < V[j]) {
			S[k] = U[i];
			i++;
		}
		else {
			S[k] = V[j];
			j++;
		}
		k++;
	}

	if (i > h) {
		for (i = j; i <= m; i++) {
			S[k++] = V[i];
		}
	}
	else {
		for (j = i; j <= h; j++) {
			S[k++] = U[j];
		}
	}
}