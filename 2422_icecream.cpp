#include <iostream>
#include <fstream>
#include <set>
using namespace std;

//문제 백준2422
int totalCnt = 0;
int iceCnt = 0;

void iceCream(int , set<int> ss[201]);// 시작 인덱스 , 못먹는 맛이 담긴 집합
int main() {

	set<int> ss[201]; // 0번방은 비우고 1- 200 만 사용 
					  // ss[1]에 1과 섞어 먹으면 맛없는 아이스크림을 추가
					  // ss[2]에 2와 섞어 먺으면 맛없는 아이스크림을 추가
					  // ex ) 맛없는 조합이 1-2, 2-3, 4-1 인 경우
					  // ss[1] ={2,4}
					  // ss[2] ={1,3}
					  // ss[3] ={2} ,ss[4] ={1} 

	int i;
	int num1, num2;// 입력을 위한 변수
	int noMixCnt; // 맛없는 조합 개수

	ifstream fin("D:\\data\\input.txt") ; // 입력 부분
	fin >> iceCnt;
	fin >> noMixCnt; 
	for ( i = 1; i <= noMixCnt; i++) {
		fin >> num1;
		fin >> num2;
		ss[num1].insert(num2);  
		ss[num2].insert(num1);
	}


	for ( i = 1; i <= iceCnt - 2; i++) {
		iceCream(i, ss);
	}


	cout << totalCnt;
	cin.get();
	return 0;
}
void iceCream(int start, set<int> ss[201]) {
	int i, j, typeAmt;
	
	for (i = start+1; i < iceCnt;i++ ) {				 // 두번째 맛: 첫번째 맛 다음부터 마지막 맛 전까지
		if (ss[i].find(start) == ss[i].end() ) {		// 첫 관문 : 첫맛과 두번째 맛이 가능한가?
			typeAmt = 2;								// 두번째 맛: i, 첫 맛: start

			for (j = i+1; j <= iceCnt; j++) {												 // 세번째 맛: 두번째 맛 다음부터 마지막 맛까지
				if (ss[i].find(j) == ss[i].end() && ss[j].find(start) == ss[j].end()) { // 두 번째 관문 : 두번째 맛과 세 번째 맛이 가능한가? 첫 번째 맛과 세번째 맛이 가능한가?	
					totalCnt++; //  조합 수 누적
				}
			}	
		}
	}
	
}

