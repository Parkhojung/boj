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

typedef struct _list{
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
		//cout << "빈 리스트입니다.";
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
int isStackTop(List *lp) {
	if (lp->size == 0) return -1;
	return lp->head->next->data;
}

int main() {
//	ifstream fin("D:\\data\\backjoonInput.txt");
	int testCase;
	string s;
	char c[50];
//	fin >> testCase;
	//fin.get();
	int option;
	int var1;
	int result;
	List list;
	init(&list);
	

	cin >> testCase;
	cin.get();
	for (int i = 0; i < testCase ; i++) {
		cin >> c;
		if (strcmp(c, "push") == 0) option = 1;
		else if (strcmp(c, "pop") == 0) option = 2;
		else if (strcmp(c, "size") == 0) option = 3;
		else if (strcmp(c, "empty") == 0) option = 4;
		else if (strcmp(c, "top") == 0) option = 5;


		switch (option)
		{
		case 1: cin >> var1; addFirst(&list, var1); break;
		case 2: deleteFirst(&list, &var1); result = var1; break;
		case 3: result = isStackSize(&list); break;
		case 4: result = isStackEmpty(&list); break;
		case 5: result = isStackTop(&list); break;
		default:

			break;
		}
		if(option != 1)
			cout << result << endl;
	}

//	cin.get();
//	cin.get();
	return 0;
}

//14
//push 1
//push 2
//top
//size
//empty
//pop
//pop
//pop
//size
//empty
//pop
//push 3
//empty
//top