#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int A, B, C;

void paper(int **&arr, int size);
void divideArr(int **&arr, int size, int**(&u)[9]);
void printArr(int **&arr, int size);
int main() {

	fstream fin("d:\\data\\input.txt");
	int N;
	int i, j;
	
	cin >> N;
	int **arr = (int**)malloc(sizeof(int*)*(N));
	for (i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int)*N);
	}

	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> arr[i][j];
	//		cout << setw(2) <<arr[i][j];
		}
	//	cout << endl;
	}

	
	paper(arr, N);


	cout << A << endl << B << endl << C;

//	cin.get();
	return 0;
}

void paper(int **&arr, int size) {
	int i, j,k,l,m;
	int aCnt, bCnt, cCnt, uSize;
	int **(u[9]);

	int var;
	int dCnt=0;
	aCnt = 0, bCnt = 0; cCnt = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (arr[i][j] == -1) {
				aCnt++; 
			}
			else if (arr[i][j] == 0) {
				bCnt++;
			}
			else if (arr[i][j] == 1) {
				cCnt++;
			}



			var = arr[i][j];
			switch (var)
			{
			case -1:
				if (bCnt != 0 || cCnt != 0) {
					divideArr(arr, size, u);
					dCnt++;
				}
				break;
			case 0:
				if (aCnt != 0 || cCnt != 0) {
					divideArr(arr, size, u);
					dCnt++;
				}
				break;
			case 1:
				if (aCnt != 0 || bCnt != 0) {
					divideArr(arr, size, u);
					dCnt++;
				}
			default:
				break;
			}

			
			if(dCnt !=0){
				
				break;
			}
		}
		if (dCnt != 0) break;
	}
	
	if (dCnt == 0) {
		if (aCnt != 0) A++;
		else if (bCnt != 0) B++;
		else if (cCnt != 0) C++;
	}
	else {
	//	free(arr);
		for (i = 0; i < 9; i++) {
			paper(u[i], size/3);
		}
	}

}

void divideArr(int **&arr,int size, int**(&u)[9]) {
	int i, j, k ,uSize;

	uSize = size / 3;

	for (i = 0; i < 9; i++) {
		u[i] = (int**)malloc(sizeof(int*)*uSize);
	}

	for (i = 0; i < 9; i++) {
		for (j = 0; j < uSize; j++) {
			u[i][j] = (int*)malloc(sizeof(int)*uSize);
		}
	}
	
	/*for (i = 0; i < uSize; i++) {
		for (j = 0; j < 3 * uSize; j++) {
			u[j/uSize][i][j%uSize] = arr[i][j];
		}
	}*/
	for (i = 0; i < 3 * uSize; i++) {
		for (j = 0; j < 3 * uSize; j++) {
			u[3*(i/uSize) + (j / uSize)][i%uSize][j%uSize] = arr[i][j];
		}
	}

	for (i = 0; i < size; i++) {
			free(arr[i]);
	}
	free(arr);
	for (i = 0; i < 9; i++) {
		//	printArr(u[i], uSize);
	}
}

void printArr(int **&arr, int size) {
	int l, m;
	for (l = 0; l < size; l++) {
		for (m = 0; m < size; m++) {

			cout <<  "arr[" << l << "][" << m << "]: " << arr[l][m] << "   ";
		//	cout << endl;

		}
		cout << endl;
	}
	cout << endl;
}