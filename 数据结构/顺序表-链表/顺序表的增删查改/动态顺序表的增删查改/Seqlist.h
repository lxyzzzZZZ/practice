#pragma once
// Sequence List
#define _CRT_SECURE_NO_WARNINGS 1
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef int size_t;
typedef struct SeqList{
	DataType *array;	// ָ�룬ָ�������ݵĿռ䣬�����Ŀռ��ڶ���
	int capacity;		// ˳������������
	int size;			// ˳�����������Ч�ĸ���
	// ��ʼֵΪ 0��ͬʱҲ��ʾ��һ����Чλ�õ��±�
}SeqList;

typedef struct SeqList	SeqList;

// ��װ�Ľӿ�

// ��ʼ��/����
void SeqListInit(SeqList *sl, size_t capacity);
void SeqListDestroy(SeqList *s1);
//����Ƿ���Ҫ����
void CheckCapacity(SeqList *sl);

// ��ɾ���
// β�壬������˳����β��
void SeqListPushBack(SeqList *sl, DataType data);

// ͷ�壬������˳����ͷ�� ([0])
void SeqListPushFront(SeqList *sl, DataType data);

// βɾ��ɾ��˳���β��������
void SeqListPopBack(SeqList *sl);

// ͷɾ��ɾ��˳���ͷ��������
void SeqListPopFront(SeqList *sl);


// ��ӡ
void SeqListPrint(SeqList *sl);
