#include "Seqlist.h"

//����Ƿ���Ҫ����
void CheckCapacity(SeqList *sl){
	if (sl->size >= sl->capacity){
		sl->array = (DataType*)realloc(sl->array, (sizeof(DataType)*(sl->capacity)) * 2);
		//realloc�����޸�ԭ���Ѿ�������ڴ��Ĵ�С
		assert(sl->array);
		sl->capacity *= 2;
	}
}

//��ʼ��˳���
void SeqListInit(SeqList *s1, size_t capacity){
	assert(s1);
	//��ʼ������Ϊ1024*4��byte
	s1->array = (DataType*)malloc(capacity * sizeof(DataType));
	assert(s1->array);
	s1->size = 0;
	s1->capacity = 3;
}

//����˳���
void SeqListDestroy(SeqList *s1){
	assert(s1);
	if (s1->array){
		free(s1->array);
	}
	s1->array = NULL;
	s1->capacity = 0;
	s1->size = 0;
}

// β�壬������˳����β��
void SeqListPushBack(SeqList *sl, DataType data){
	assert(sl);
	CheckCapacity(sl);
	sl->array[sl->size] = data;
	sl->size++;
}


// ͷ�壬������˳����ͷ�� ([0])
void SeqListPushFront(SeqList *sl, DataType data){
	assert(sl);
	CheckCapacity(sl);
	for (int i = sl->size; i >= 0; i--){
		sl->array[i] = sl->array[i - 1];
	}
	sl->size++;
	sl->array[0] = data;
}

// βɾ��ɾ��˳���β��������
void SeqListPopBack(SeqList *sl){
	assert(sl);
	if (sl->size <= 0){
		printf("sl is empty\n");
		return;
	}
	sl->size--;
}
// ͷɾ��ɾ��˳���ͷ��������
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

// ��ӡ
void SeqListPrint(SeqList *sl){
	assert(sl);
	printf("˳���");
	for (int i = 0; i < sl->size; i++){
		printf("%d ", sl->array[i]);
	}
	printf("\n");
	printf("size=%d, capacity=%d \n", sl->size, sl->capacity);
}
