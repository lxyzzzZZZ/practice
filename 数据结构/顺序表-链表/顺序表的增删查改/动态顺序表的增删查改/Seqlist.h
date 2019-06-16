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
	DataType *array;	// 指针，指向存放数据的空间，真正的空间在堆上
	int capacity;		// 顺序表整体的容量
	int size;			// 顺序表中真正有效的个数
	// 初始值为 0，同时也表示下一个有效位置的下标
}SeqList;

typedef struct SeqList	SeqList;

// 封装的接口

// 初始化/销毁
void SeqListInit(SeqList *sl, size_t capacity);
void SeqListDestroy(SeqList *s1);
//检查是否需要扩容
void CheckCapacity(SeqList *sl);

// 增删查改
// 尾插，插入在顺序表的尾部
void SeqListPushBack(SeqList *sl, DataType data);

// 头插，插入在顺序表的头部 ([0])
void SeqListPushFront(SeqList *sl, DataType data);

// 尾删，删除顺序表尾部的数据
void SeqListPopBack(SeqList *sl);

// 头删，删除顺序表头部的数据
void SeqListPopFront(SeqList *sl);


// 打印
void SeqListPrint(SeqList *sl);
