#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int HPartype;
typedef struct Heap{
	HPartype* arr;
	int size;
	int capacity;
}Heap,*heap;

void HeapInit(heap hp, HPartype* arr, int n){
	assert(hp);

	hp->arr = (HPartype*)malloc(sizeof(HPartype)*n);
	if (hp == NULL){
		printf("初始化失败\n");
		return;
	}
	hp->size = 0;
	hp->capacity = n;
	return;
}

void Swap(HPartype *a, HPartype *b)
{
	HPartype tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void HeapDestory(heap hp){
	assert(hp);
	if (hp){
		free(hp->arr);
	}
	hp->capacity = 0;
	hp->size = 0;
	return 0;
}

void AdjustDown(heap hp, int root)
{
	int minChild = 0;
	int parent = root;
	int left = 0;
	int right = 0;

	assert(NULL != hp);

	//越界
	while (parent < hp->size)
	{
		left = parent * 2 + 1;
		right = parent * 2 + 2;

		if (left >= hp->size)
		{
			return;
		}
		else
		{
			;
		}
		//假设左孩子小，如果左孩子大的话会在if判断语句中进行调整
		minChild = left;

		//确保右孩子存在，并且右孩子比左孩子小
		//right最大即为数组最后一个下标，其小于hp->size
		if ((right < hp->size) && (hp->arr[right] < hp->arr[left]))
		{
			minChild = right;
		}
		else
		{
			;
		}

		if (hp->arr[minChild] > hp->arr[parent])
		{
			return;
		}
		else
		{
			Swap(hp->arr + minChild, hp->arr + parent);
			parent = minChild;
		}
	}

	return;
}

void AdjustUp(heap hp, int child){
	int parent = 0;
	assert(hp);
	while (1){
		//数组实现二叉树  子节点查找双亲结点的公式
		parent = (child - 1) / 2;
		if ((0 == child % 2) && (hp->arr[child] > hp->arr[child - 1])){
			return;
		}
		else{
			;
		}
		//与根比较
		if (hp->arr[child] > hp->arr[parent])
		{
			//满足堆
			return;
		}
		else
		{
			Swap(hp->arr + child, hp->arr + parent);
		}

		//已经调整到根结点
		if (0 == parent)
		{
			return;
		}
		else
		{
			child = parent;
		}
	}
}
//加入一个元素堆 的性质不变
void HeapPush(heap hp, HPartype x){
	assert(hp);
	assert(hp->size < hp->capacity);
	//尾插
	hp->arr[hp->size++] = x;
	AdjustUp(hp, hp->size - 1);
	return;
}

void HeapPop(Heap * hp)
{
	assert(NULL != hp);
	assert(hp->size > 0);

	//用数组中的最后一个元素去替换首元素，相当于减少一个元素，再向下调整
	hp->arr[0] = hp->arr[hp->size - 1];
	AdjustDown(hp, 0);
	return;
}

int HeapIsEmpty(Heap * hp)
{
	assert(NULL != hp);

	return 0 == hp->size ? 1 : 0;
}

void HeapPop(heap hp)
{
	assert(NULL != hp);
	assert(hp->size > 0);

	//用数组中的最后一个元素去替换首元素，相当于减少一个元素，再向下调整
	hp->arr[0] = hp->arr[hp->size - 1];
	AdjustDown(hp, 0);

	return;
}

void HeapSort(HPartype* ar, int size)
{
	//建大堆
	int i = 0;
	int left = 0;
	int right = 0;
	int maxChild = 0;

	for (i = (size - 2) / 2; i >= 0; i--)
	{
		left = i * 2 + 1;
		right = i * 2 + 2;
		//假设左孩子大
		maxChild = left;

		//右孩子存在，并且右孩子大于左孩子
		if ((right < size) && (ar[right] > ar[left]))
		{
			maxChild = right;
		}
		else
		{
			;
		}

		if (ar[maxChild] > ar[i])
		{
			Swap(ar + maxChild, ar + i);
			AdjustDown(ar, size, maxChild);
		}
		else
		{
			;
		}
	}

	//建好堆后
	for (i = 0; i < size; i++)
	{
		Swap(ar, ar + size - 1 - i);
		AdjustDown(ar, size - 1 - i, 0);
	}

	return;
}

void arPrint(heap hp)
{
	int i = 0;

	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->arr[i]);
	}

	printf("\n");

	return;
}