#include <iostream>
#include <fstream>
using namespace std;


int best;
int score[301] = { 0, };
int cnt = 1;
int max;
void stair(int psSize, int value, int n);
int main() {
	 // 1-300 인덱스 사용
	bool conti = false;
	

	fstream fin("d:\\data\\input.txt");

	int i;
	int N = 0;
	fin >> N;
	max = N;
	for (i = 1; i <= max; i++) {
		fin >> score[i];
	}
	
	stair( 2, score[1],1);
	
	int res= -1000000;
	/*for (i = 1; i <= 100000; i++) {
		
		if (res < best[i] ) res = best[i];
	}*/
	cout << best;

	return 0;
}

void stair( int psSize, int value, int n) { // score 배열, psSize: prev step size, value ,누적된 계단값, 이동할 계단 인덱스

	cout << __FUNCTION__ << n << endl;

	if (n == max) {
		if(best < value)
			best = value ;
		return;
	}
	if(n > max){
		return;
	}

	if (psSize == 2 && n < max) {
		stair(1, value + score[n + 1], n + 1);
		stair(2, value + score[n + 2], n + 2);
	}
	if (psSize == 1 && n < max) {
		stair(2, value + score[n + 2], n + 2);
		
	}
}
