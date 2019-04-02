#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define M 10
#define N 10
static string stu[M][N];
static int n = 0;
static int m = 0;
void Init()
{
	stu[0][0] = " ";
	cout << "请输入科目数：";
	cin >> n;
	cout << "请输入学生人数：";
	cin >> m;
	cout << "请输入科目：" << endl;;
	for (int i = 1; i <= n; i++)
	{
		cin >> stu[0][i];
	}
}
void Import()
{
	for (int i = 1; i <= m; i++)
	{
		cout << "请输入学生姓名：";
		cin >> stu[i][0];
		cout << "请输入学生成绩----》" << endl;
		for (int j = 1; j <= n; j++)
		{
			cout << stu[0][j] << ": ";
			cin >> stu[i][j];
		}
	}

}
void Check()
{
	while (1)
	{
		cout << "---0.查看所有学生信息---" << endl;
		cout << "---1.查看单个学生信息---" << endl;
		cout << "请选择：";
		int c = 0;
		cin >> c;
		string s;
		switch (c)
		{
		case 0:
			for (int i = 0; i <= m; i++)
			{
				for (int j = 0; j <= n; j++)
				{
					cout << stu[i][j] << "\t";
				}
				cout << "\t";
				cout << endl;
			}
			return;
		case 1:
			cout << "请输入学生姓名：";
			cin >> s;
			for (int i = 0; i <= m; i++)
			{
				if (s == stu[i][0])
				{
					cout << s.c_str() << endl;
					for (int j = 1; j <= n; j++)
					{
						cout << stu[0][j].c_str() << ": " << stu[i][j].c_str() << endl;
					}
				}
			}
			return;
		default:
			cout << "输入错误！" << endl;
			break;
		}
	}
}
void Menu()
{
	cout << "|-----请选择-------------|" << endl;
	cout << "|-----1.输入信息---------|" << endl;
	cout << "|-----2.查看信息---------|" << endl;
	cout << "|-----3.排序-------------|" << endl;
	cout << "|-----4.退出-------------|" << endl;
}
void Swapp(string& s1, string& s2)
{
	string tmp = s1;
	s1 = s2;
	s2 = tmp;
}
void Sort()
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = i + 1; j <= m; j++)
		{
			if (stu[i][0].length() > stu[j][0].length())
			{
				for (int k = 0; k <= n; k++)
				{
					Swapp(stu[i][k], stu[j][k]);
				}
			}
		}
	}
	cout << "排序完成!" << endl;
}
int main()
{
	Init();
	while (1)
	{
		int a = 0;
		Menu();
		cout << "请选择功能：";
		cin >> a;
		switch (a)
		{
		case 1:
			Import();
			break;
		case 2:
			Check();
			break;
		case 3:
			Sort();
			break;
		case 4:
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误！,请重新输入！！！" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}









































//void find(string s,string name[20],string grade[20],int M)
//{
//	int k = 0;
//	for (int i = 0; i < M; i++)
//	{
//		if (s == name[i])
//		{
//			cout << name[i].c_str() << "的成绩:" << grade[i].c_str() << endl;
//			return;
//		}
//	}
//}
//void Deplay(string name[20], string grade[20], int M)
//{
//	for (int i = 0; i < M; i++)
//	{
//		cout << name[i].c_str() << "的成绩:" << grade[i].c_str() << endl;
//	}
//}
//int main()
//{
//	int M = 1;
//	int N = 1;
//	cout << "输入学生人数M：";
//	cin >> M;
//	string name[20] = {};
//	string grade[20] = {};
//	for (int i = 0; i < M; i++)
//	{
//		cout << "输入姓名:";
//		cin >> name[i];
//		cout << "输入" << name[i].c_str() << "的成绩：";
//		cin >> grade[i];
//	}
//	string s = "";
//	cout << "请输入要查找的学生姓名：";
//	cin >> s;
//	find(s, name, grade, M);
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = i + 1; j < M; j++)
//		{
//			if (name[j] > name[i])
//			{
//				string tmp = name[j];
//				name[j] = name[i];
//				name[i] = tmp;
//				string tmp2 = grade[j];
//				grade[j] = grade[i];
//				grade[i] = tmp2;
//			}
//		}
//	}
//	cout << "打印所有信息" << endl;
//	Deplay(name, grade, M);
//	system("pause");
//	return 0;
//}
//using namespace std;
//typedef struct Student{
//	char* name;
//	int* Grade;
//	int sum;
//	stu* next;
//}*Stu,stu;
//
//typedef struct S
//{
//	stu* head;
//}*S,S;
//
////初始化
//void StuInit(S s){
//	s->head = NULL;
//}
//
//
////创建节点
//Stu BuyNode(){
//	Stu new_node = (stu*)malloc(sizeof(stu*));
//	if (new_node == NULL){
//		return 0;//创建空间失败
//	}
//	new_node->name = "0";
//	new_node->Grade = NULL;
//	new_node->sum = 0;
//	return new_node;
//}
//void StuIn(S s, int N)
//{
//
//	Stu ret = NULL;
//	ret = BuyNode();
//	cout << "输入姓名：";
//	cin >> ret->name;
//	cout << "输入成绩:";
//	while (N--)
//	{
//		cin >> *(ret->Grade);
//		ret->sum += *(ret->Grade);
//		*(ret->Grade)++;
//	}
//	if (!s->head)
//	{
//		s->head = ret;
//	}
//	else
//	{
//		s->head->next = ret;
//	}
//}
//
//int main(){
//	S head;
//	StuInit(head);
//	StuIn(head, 3);
//	system("pause");
//	return 0;
//}
//void Init(stu s,int N){
//	cout << "请输入学生姓名：";
//	cin >> s->arr;
//	for (int i = 0; i < N; i++){
//		cout << "请输入成绩";
//		cin >> s->Grade[i];
//		s->sum += s->Grade[i];
//	}
//}
//void deplay(stu s){
//	cout << "学生：" << s->arr << "成绩：" << s->Grade << "总成绩：" << s->sum << endl;
//}
//void  Menu(){
//	cout << "------  请选择  ------" << endl;
//	cout << "------1.添加信息------" << endl;
//	cout << "------2.查看信息------" << endl;
//	cout << "------3.  退出  ------" << endl;
//}
//int main(){
//	while (1){
//		switch ()
//	}
//	system("pause");
//}









//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//
//typedef int SLDataType;
//
//typedef struct SListNode{
//	SLDataType data;
//	struct SListNode* next;
//}SListNode, *SL;
//
//typedef struct SList{
//	SL head;
//}SList, *sl;
//
////初始化
//void SListInit(SList* plist){
//	plist->head = NULL;
//}
//
//
//
////销毁
//void SListDestroy(SList* plist){
//	SListNode* next;
//	for (SListNode *cur = plist->head; cur != NULL; cur = next){
//		next = cur->next;
//		//free(cur);
//	}
//	plist->head = NULL;
//	if (plist){
//		printf("销毁成功\n");
//	}
//}
////创建节点
//SLDataType* BuySListNode(SLDataType x){
//	SL new_node = (SListNode*)malloc(sizeof(SListNode*));
//	if (new_node == NULL){
//		return -1;//创建空间失败
//	}
//	new_node->data = x;
//	new_node->next = NULL;
//	return new_node;
//}
//
////头插
//void SListPushFront(SList* plist, SLDataType x){
//	assert(plist);
//	SListNode* Node = NULL;
//	Node = BuySListNode(x);
//	Node->next = plist->head;
//	plist->head = Node;
//}
//
//
////尾插
//void SListPushBack(SList* plist, SLDataType x){
//	assert(plist);
//	if (plist->head == NULL)
//	{
//		SListPushFront(plist, x);
//		return;
//	}
//	SListNode* cur = plist->head;
//	SListNode* node = BuySListNode(x);
//	for (; cur->next != NULL; cur = cur->next)
//	{
//		;
//	}
//	cur->next = node;
//}
//
////头删
//void SListPopFront(sl plist){
//	assert(plist);
//	assert(plist->head != NULL);
//	SL cur = plist->head;
//	plist->head = cur->next;
//	//free(cur);
//}
//
////尾删
//void SListPopBack(SList* plist){
//	assert(plist);
//	assert(plist->head != NULL);
//	SListNode* cur = plist->head;
//	for (; cur->next->next != NULL; cur = cur->next){
//		;
//	}
//	//free(cur->next);
//	cur->next = NULL;
//}
////打印
//void SListPrint(SList* plist){
//	assert(plist);
//	for (SListNode* cur = plist->head; cur != NULL; cur = cur->next){
//		printf("%d -> ", cur->data);
//	}
//	printf("NULL\n");
//}
//
//
//int main(){
//	SList list;
//	SListInit(&list);
//	SListPushFront(&list, 3);
//	SListPushFront(&list, 2);
//	SListPushFront(&list, 1);
//	SListPushBack(&list, 4);
//	SListPrint(&list);
//	SListPopBack(&list);
//	SListPrint(&list);
//	SListPopFront(&list);
//	SListPrint(&list);
//	SListDestroy(&list);
//	system("pause");
//	return 0;
//}