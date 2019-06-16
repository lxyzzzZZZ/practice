#include "Seqlist.h"

//检查是否需要扩容
void CheckCapacity(SeqList *sl){
	if (sl->size >= sl->capacity){
		sl->array = (DataType*)realloc(sl->array, (sizeof(DataType)*(sl->capacity)) * 2);
		//realloc用于修改原先已经分配的内存块的大小
		assert(sl->array);
		sl->capacity *= 2;
	}
}

//初始化顺序表
void SeqListInit(SeqList *s1, size_t capacity){
	assert(s1);
	//初始化容量为1024*4个byte
	s1->array = (DataType*)malloc(capacity * sizeof(DataType));
	assert(s1->array);
	s1->size = 0;
	s1->capacity = 3;
}

//销毁顺序表
void SeqListDestroy(SeqList *s1){
	assert(s1);
	if (s1->array){
		free(s1->array);
	}
	s1->array = NULL;
	s1->capacity = 0;
	s1->size = 0;
}

// 尾插，插入在顺序表的尾部
void SeqListPushBack(SeqList *sl, DataType data){
	assert(sl);
	CheckCapacity(sl);
	sl->array[sl->size] = data;
	sl->size++;
}


// 头插，插入在顺序表的头部 ([0])
void SeqListPushFront(SeqList *sl, DataType data){
	assert(sl);
	CheckCapacity(sl);
	for (int i = sl->size; i >= 0; i--){
		sl->array[i] = sl->array[i - 1];
	}
	sl->size++;
	sl->array[0] = data;
}

// 尾删，删除顺序表尾部的数据
void SeqListPopBack(SeqList *sl){
	assert(sl);
	if (sl->size <= 0){
		printf("sl is empty\n");
		return;
	}
	sl->size--;
}
// 头删，删除顺序表头部的数据
void SeqListPopFront(SeqList *sl){
	assert(sl);
	if (sl->size <= 0){
		printf("sl is empty\n");
		return;
	}
	sl->size = 0;
	for (int i = 0; i < sl->size; i++){
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}

// 打印
void SeqListPrint(SeqList *sl){
	assert(sl);
	printf("顺序表：");
	for (int i = 0; i < sl->size; i++){
		printf("%d ", sl->array[i]);
	}
	printf("\n");
	printf("size=%d, capacity=%d \n", sl->size, sl->capacity);
}
