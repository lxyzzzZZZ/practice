
#include "Seqlist.h"
SeqList s;

int main(){

	SeqListInit(&s, 1024);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	system("pause");
	return 0;
}