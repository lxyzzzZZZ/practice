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

//初始化
void SListInit(SList* plist){
	plist->head = NULL;
}

//销毁
void SListDestroy(SList* plist){
	SListNode* next;
	for (SListNode *cur = plist->head; cur != NULL; cur = next){
		next = cur->next;
		//free(cur);
	}
	plist->head = NULL;
	if (plist){
		printf("销毁成功\n");
	}
}
//创建节点
SLDataType* BuySListNode(SLDataType x){
	SL new_node = (SListNode*)malloc(sizeof(SListNode*));
	if (new_node == NULL){
		return -1;//创建空间失败
	}
	new_node->data = x;
	new_node->next = NULL;
	return new_node;
}

//头插
void SListPushFront(SList* plist, SLDataType x){
	assert(plist);
	SListNode* Node = NULL;
	Node = BuySListNode(x);
	Node->next = plist->head;
	plist->head = Node;
}


//尾插
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

//头删
void SListPopFront(sl plist){
	assert(plist);
	assert(plist->head != NULL);
	SL cur = plist->head;
	plist->head =cur->next;
	//free(cur);
}

//尾删
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
//打印
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