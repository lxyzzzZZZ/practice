#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int STDataType;
// ���ö�̬˳���ʵ��ջ
typedef struct Stack
{
	STDataType* a;
	int top; // ջ��
	int capacity; // ����
}Stack,*stack;
void StackInit(Stack* ps,int capacity){
	ps = (Stack*)malloc(sizeof(Stack)*capacity);
	ps->top = -1;
}
void StackDestory(stack ps){
	assert(ps);
	while (ps->top >= 0){
		free(ps->a[ps->top]);
		ps->top--;
	}
}
void StackPush(stack ps, STDataType x){
	assert(ps);
	assert(ps->top < ps->capacity);
	ps->top++;
	ps->a[ps->top] == x;
}
void StackPop(stack ps){
	assert(ps);
	free(ps->a[ps->top]);
	ps->top--;
}
STDataType StackTop(stack ps){
	assert(ps);
	return ps->a[ps->top];
}
int StackEmpty(Stack* ps){
	assert(ps);
	if (ps->top >= 0){
		return 1;
	}
	else{
		return -1;
	}
}
int StackSize(Stack* ps){
	return ps->top;
}
//void TestStack();





// ���þ�̬˳���ʵ��ջ
#define MAX_LEN	(100)

typedef struct {
	STDataType	array[MAX_LEN];
	int			top;	// ְ�����ԭ���� size
}	Stack;


void StackInit(Stack *stack) {
	stack->top = 0;
}

void StackDestroy(Stack *stack) {
	stack->top = 0;
}

// ��ɾ�Ĳ�
// ֻ�ܴ�ջ������
void StackPush(Stack *stack, STDataType val) {
	assert(stack);
	assert(stack->top < MAX_LEN);

	stack->array[stack->top] = val;
	stack->top++;
}

// ֻ�ܴ�ջ��ɾ��
void StackPop(Stack *stack) {
	assert(stack);
	assert(stack->top > 0);

	stack->top--;
}

// ����ջ��Ԫ��
STDataType StackTop(Stack *stack) {
	assert(stack);
	assert(stack->top > 0);

	return stack->array[stack->top - 1];
}

// �ж��Ƿ�Ϊ��
int StackEmpty(const Stack *stack) {
	return stack->top == 0 ? 1 : 0;
}

// ����ջ�����ݸ���
int StackSize(const Stack *stack) {
	return stack->top;
}
