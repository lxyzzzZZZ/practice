#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

typedef struct SListNode{
	SLDataType data;
	struct SListNode* next;
}SListNode,*SL;

typedef struct SList{
	SL head;
}SList,*sl;

//��ʼ��
void SListInit(SList* plist){
	plist->head = NULL;
}

//����
void SListDestroy(SList* plist){
	SListNode* next;
	for (SListNode *cur = plist->head; cur != NULL; cur = next){
		next = cur->next;
		//free(cur);
	}
	plist->head = NULL;
	if (plist){
		printf("���ٳɹ�\n");
	}
}
//�����ڵ�
SLDataType* BuySListNode(SLDataType x){
	SL new_node = (SListNode*)malloc(sizeof(SListNode*));
	if (new_node == NULL){
		return -1;//�����ռ�ʧ��
	}
	new_node->data = x;
	new_node->next = NULL;
	return new_node;
}

//ͷ��
void SListPushFront(SList* plist, SLDataType x){
	assert(plist);
	SListNode* Node = NULL;
	Node = BuySListNode(x);
	Node->next = plist->head;
	plist->head = Node;
}


//β��
void SListPushBack(SList* plist, SLDataType x){
	assert(plist);
	if (plist->head == NULL)
	{
		SListPushFront(plist, x);
		return;
	}
	SListNode* cur = plist->head;
	SListNode* node = BuySListNode(x);
	for (; cur->next != NULL; cur = cur->next)
	{
		;
	}
	cur->next = node;
}

//ͷɾ
void SListPopFront(sl plist){
	assert(plist);
	assert(plist->head != NULL);
	SL cur = plist->head;
	plist->head =cur->next;
	//free(cur);
}

//βɾ
void SListPopBack(SList* plist){
	assert(plist);
	assert(plist->head != NULL);
	SListNode* cur = plist->head;
	for (; cur->next->next != NULL; cur = cur->next){
		;
	}
	//free(cur->next);
	cur->next = NULL;
}
//��ӡ
void SListPrint(SList* plist){
	assert(plist);
	for (SListNode* cur = plist->head; cur != NULL; cur = cur->next){
		printf("%d -> ", cur->data);
	}
	printf("NULL\n");
}


int main(){
	SList list;
	SListInit(&list);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPushBack(&list, 4);
	SListPrint(&list);
	SListPopBack(&list);
	SListPrint(&list);
	SListPopFront(&list);
	SListPrint(&list);
	SListDestroy(&list);
	system("pause");
	return 0;
}