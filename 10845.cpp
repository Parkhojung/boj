//정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
//
//명령은 총 여섯 가지이다.
//
//push X : 정수 X를 큐에 넣는 연산이다.
//pop : 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
//	size : 큐에 들어있는 정수의 개수를 출력한다.
//	empty : 큐가 비어있으면 1, 아니면 0을 출력한다.
//	front : 큐의 가장 앞에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
//	back : 큐의 가장 뒤에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.

#include <iostream>
//#include <fstream>
#include <cstring>
#include <malloc.h>
using namespace std;
typedef int DATA;

typedef struct _node {
	struct _node * prev;
	struct _node * next;
	DATA data;
}Node;

typedef struct _list {
	Node* head;
	Node* tail;
	int size;
}List;


int init(List *lp) {
	if (lp == NULL) return -1;

	lp->head = (Node*)malloc(sizeof(Node));
	if (lp->head == NULL)return false;
	lp->tail = (Node*)malloc(sizeof(Node));
	if (lp->tail == NULL) {
		free(lp->head);
		return -1;
	}

	lp->head->data = lp->tail->data = 0;

	lp->head->next = lp->tail;
	lp->head->prev = lp->head;

	lp->tail->prev = lp->head;
	lp->tail->next = lp->tail;

	lp->size = 0;
	return 1;
}

int addFirst(List *lp, DATA data) {
	if (lp == NULL) return -1;

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return -1;

	newNode->data = data;

	newNode->next = lp->head->next;
	lp->head->next = newNode;
	newNode->next->prev = newNode;
	newNode->prev = lp->head;
	lp->size++;
	return 1;
}
int deleteFirst(List *lp, DATA* data) {
	if (lp == NULL) return -1;
	if (lp->size == 0) {
		*data = -1;
		return -1;
	}
	*data = lp->head->next->data;
	lp->head->next = lp->head->next->next;
	lp->head->next->prev = lp->head;
	lp->size--;
	return 1;

}
int deleteLast(List *lp, DATA* data) {
	if (lp == NULL)return -1;

	if (lp->size == 0) {
		*data = -1;
		return -1;
	}
	*data = lp->tail->prev->data;// 삭제할 데이터 
	Node* dp = lp->tail->prev;

	lp->tail->prev->prev->next = lp->tail;// 노드정리
	lp->tail->prev = lp->tail->prev->prev;

	free(dp);
	lp->size--;
	return 1;
}
int isStackSize(List *lp) {
	return lp->size;
}
int isStackEmpty(List *lp) {
	if (lp->size == 0) return 1;
	else return 0;
}
int isFront(List *lp) {
	if (lp == NULL) return -1;

	if (lp->size == 0)return -1;
	else {
		return lp->tail->prev->data;
	}
}
int isBack(List *lp) {
	if (lp == NULL) return -1;

	if (lp->size == 0)return -1;
	else {
		return lp->head->next->data;
	}
}

int main() {
		
	int testCase;
	string s;
	char c[50];
	int option;
	int var1;
	int result;
	List list;
	init(&list);

//	ifstream fin("D:\\data\\backjoonInput.txt");
//	fin >> testCase;
//	fin.get();
	cin >> testCase;
	cin.get();
	for (int i = 0; i < testCase; i++) {
	//	fin >> c;
		cin >> c;
		if (strcmp(c, "push") == 0) option = 1;
		else if (strcmp(c, "pop") == 0) option = 2;
		else if (strcmp(c, "size") == 0) option = 3;
		else if (strcmp(c, "empty") == 0) option = 4;
		else if (strcmp(c, "front") == 0) option = 5;
		else if (strcmp(c, "back") == 0) option = 6;

		switch (option)
		{
		case 1: 
			//fin >> var1;
			cin >> var1; addFirst(&list, var1); break;
		case 2: deleteLast(&list, &var1); result = var1; break;
		case 3: result = isStackSize(&list); break;
		case 4: result = isStackEmpty(&list); break;
		case 5: result = isFront(&list); break;
		case 6: result = isBack(&list); break;
		default:

			break;
		}
		if (option != 1)
			cout << result << endl;
	}

		//cin.get();
		//cin.get();
	return 0;
}
