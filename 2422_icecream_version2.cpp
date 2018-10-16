#include <iostream>
//#include <fstream>
#include <set>
using namespace std;

//문제 백준2422
int totalCnt = 0;
int iceCnt = 0;

set<int> ss[201];// 0번방은 비우고 1- 200 만 사용 
					  // ss[1]에 1과 섞어 먹으면 맛없는 아이스크림을 추가
					  // ss[2]에 2와 섞어 먺으면 맛없는 아이스크림을 추가
					  // ex ) 맛없는 조합이 1-2, 2-3, 4-1 인 경우
					  // ss[1] ={2,4}
					  // ss[2] ={1,3}
					  // ss[3] ={2} ,ss[4] ={1} 

int combnt(int,int);// 시작 인덱스 , 못먹는 맛이 담긴 집합
int main() {

					 
	int i;
	int num1, num2;// 입력을 위한 변수
	int noMixCnt; // 맛없는 조합 개수

	//ifstream fin("D:\\data\\input.txt"); // 입력 부분
	cin >> iceCnt;
	cin >> noMixCnt;


	for (i = 1; i <= noMixCnt; i++) {
		cin >> num1;
		cin >> num2;
		ss[num1].insert(num2);
		ss[num2].insert(num1);
	}

	totalCnt += combnt(iceCnt, 3);
	totalCnt -= noMixCnt*(iceCnt - 2);
	for (i = 1; i <= iceCnt; i++) {
		totalCnt += combnt(ss[i].size(), 2);
	}


	cout << totalCnt;
//	cin.get();
	return 0;
}
int combnt(int n,int m) {
	int nres=1, mres=1;
	if (n == m) return 1;
	if (n < m) return 0;

	for (int i = n; i > n - m; i--) {
		nres *= i;
	}
	for (int i = m; i > 1; i--) {
		mres *= i;
	}
	return nres / mres;
}

