#include <iostream>
//#include <fstream>
#include <set>
using namespace std;

//���� ����2422
int totalCnt = 0;
int iceCnt = 0;

set<int> ss[201];// 0������ ���� 1- 200 �� ��� 
					  // ss[1]�� 1�� ���� ������ ������ ���̽�ũ���� �߰�
					  // ss[2]�� 2�� ���� ������ ������ ���̽�ũ���� �߰�
					  // ex ) ������ ������ 1-2, 2-3, 4-1 �� ���
					  // ss[1] ={2,4}
					  // ss[2] ={1,3}
					  // ss[3] ={2} ,ss[4] ={1} 

int combnt(int,int);// ���� �ε��� , ���Դ� ���� ��� ����
int main() {

					 
	int i;
	int num1, num2;// �Է��� ���� ����
	int noMixCnt; // ������ ���� ����

	//ifstream fin("D:\\data\\input.txt"); // �Է� �κ�
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

