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
	cout << "�������Ŀ����";
	cin >> n;
	cout << "������ѧ��������";
	cin >> m;
	cout << "�������Ŀ��" << endl;;
	for (int i = 1; i <= n; i++)
	{
		cin >> stu[0][i];
	}
}
void Import()
{
	for (int i = 1; i <= m; i++)
	{
		cout << "������ѧ��������";
		cin >> stu[i][0];
		cout << "������ѧ���ɼ�----��" << endl;
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
		cout << "---0.�鿴����ѧ����Ϣ---" << endl;
		cout << "---1.�鿴����ѧ����Ϣ---" << endl;
		cout << "��ѡ��";
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
			cout << "������ѧ��������";
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
			cout << "�������" << endl;
			break;
		}
	}
}
void Menu()
{
	cout << "|-----��ѡ��-------------|" << endl;
	cout << "|-----1.������Ϣ---------|" << endl;
	cout << "|-----2.�鿴��Ϣ---------|" << endl;
	cout << "|-----3.����-------------|" << endl;
	cout << "|-----4.�˳�-------------|" << endl;
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
	cout << "�������!" << endl;
}
int main()
{
	Init();
	while (1)
	{
		int a = 0;
		Menu();
		cout << "��ѡ���ܣ�";
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
			cout << "�������,���������룡����" << endl;
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
//			cout << name[i].c_str() << "�ĳɼ�:" << grade[i].c_str() << endl;
//			return;
//		}
//	}
//}
//void Deplay(string name[20], string grade[20], int M)
//{
//	for (int i = 0; i < M; i++)
//	{
//		cout << name[i].c_str() << "�ĳɼ�:" << grade[i].c_str() << endl;
//	}
//}
//int main()
//{
//	int M = 1;
//	int N = 1;
//	cout << "����ѧ������M��";
//	cin >> M;
//	string name[20] = {};
//	string grade[20] = {};
//	for (int i = 0; i < M; i++)
//	{
//		cout << "��������:";
//		cin >> name[i];
//		cout << "����" << name[i].c_str() << "�ĳɼ���";
//		cin >> grade[i];
//	}
//	string s = "";
//	cout << "������Ҫ���ҵ�ѧ��������";
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
//	cout << "��ӡ������Ϣ" << endl;
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
////��ʼ��
//void StuInit(S s){
//	s->head = NULL;
//}
//
//
////�����ڵ�
//Stu BuyNode(){
//	Stu new_node = (stu*)malloc(sizeof(stu*));
//	if (new_node == NULL){
//		return 0;//�����ռ�ʧ��
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
//	cout << "����������";
//	cin >> ret->name;
//	cout << "����ɼ�:";
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
//	cout << "������ѧ��������";
//	cin >> s->arr;
//	for (int i = 0; i < N; i++){
//		cout << "������ɼ�";
//		cin >> s->Grade[i];
//		s->sum += s->Grade[i];
//	}
//}
//void deplay(stu s){
//	cout << "ѧ����" << s->arr << "�ɼ���" << s->Grade << "�ܳɼ���" << s->sum << endl;
//}
//void  Menu(){
//	cout << "------  ��ѡ��  ------" << endl;
//	cout << "------1.�����Ϣ------" << endl;
//	cout << "------2.�鿴��Ϣ------" << endl;
//	cout << "------3.  �˳�  ------" << endl;
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
////��ʼ��
//void SListInit(SList* plist){
//	plist->head = NULL;
//}
//
//
//
////����
//void SListDestroy(SList* plist){
//	SListNode* next;
//	for (SListNode *cur = plist->head; cur != NULL; cur = next){
//		next = cur->next;
//		//free(cur);
//	}
//	plist->head = NULL;
//	if (plist){
//		printf("���ٳɹ�\n");
//	}
//}
////�����ڵ�
//SLDataType* BuySListNode(SLDataType x){
//	SL new_node = (SListNode*)malloc(sizeof(SListNode*));
//	if (new_node == NULL){
//		return -1;//�����ռ�ʧ��
//	}
//	new_node->data = x;
//	new_node->next = NULL;
//	return new_node;
//}
//
////ͷ��
//void SListPushFront(SList* plist, SLDataType x){
//	assert(plist);
//	SListNode* Node = NULL;
//	Node = BuySListNode(x);
//	Node->next = plist->head;
//	plist->head = Node;
//}
//
//
////β��
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
////ͷɾ
//void SListPopFront(sl plist){
//	assert(plist);
//	assert(plist->head != NULL);
//	SL cur = plist->head;
//	plist->head = cur->next;
//	//free(cur);
//}
//
////βɾ
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
////��ӡ
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