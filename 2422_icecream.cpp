#include <iostream>
#include <fstream>
#include <set>
using namespace std;

//���� ����2422
int totalCnt = 0;
int iceCnt = 0;

void iceCream(int , set<int> ss[201]);// ���� �ε��� , ���Դ� ���� ��� ����
int main() {

	set<int> ss[201]; // 0������ ���� 1- 200 �� ��� 
					  // ss[1]�� 1�� ���� ������ ������ ���̽�ũ���� �߰�
					  // ss[2]�� 2�� ���� ������ ������ ���̽�ũ���� �߰�
					  // ex ) ������ ������ 1-2, 2-3, 4-1 �� ���
					  // ss[1] ={2,4}
					  // ss[2] ={1,3}
					  // ss[3] ={2} ,ss[4] ={1} 

	int i;
	int num1, num2;// �Է��� ���� ����
	int noMixCnt; // ������ ���� ����

	ifstream fin("D:\\data\\input.txt") ; // �Է� �κ�
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
	
	for (i = start+1; i < iceCnt;i++ ) {				 // �ι�° ��: ù��° �� �������� ������ �� ������
		if (ss[i].find(start) == ss[i].end() ) {		// ù ���� : ù���� �ι�° ���� �����Ѱ�?
			typeAmt = 2;								// �ι�° ��: i, ù ��: start

			for (j = i+1; j <= iceCnt; j++) {												 // ����° ��: �ι�° �� �������� ������ ������
				if (ss[i].find(j) == ss[i].end() && ss[j].find(start) == ss[j].end()) { // �� ��° ���� : �ι�° ���� �� ��° ���� �����Ѱ�? ù ��° ���� ����° ���� �����Ѱ�?	
					totalCnt++; //  ���� �� ����
				}
			}	
		}
	}
	
}

