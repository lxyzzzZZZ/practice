#include  <iostream>
#include <list>
#include <vector>

//因为list的底层结构为带头结点的双向循环链表

using namespace std;

class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int , int, int):" << this << endl;
	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void PrintList(const list<int>& L)
{
	list<int>::const_iterator it = L.cbegin();
	while (it != L.cend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void ListPrint(const list<int>& L)
{
	list<int>::const_reverse_iterator it = L.crbegin();
	while (it != L.crend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}void TestList1()
{
	cout << "TestList1:" << endl;

	list<int> l1;
	list<int> l2(4,100);
	list<int> l3(l2.begin(),l2.end());
	list<int> l4(l3);

	int arr[] = {16,2,77,29 };
	list<int> l5(arr, arr + sizeof(arr) / sizeof(int));

	PrintList(l1);
	PrintList(l2);
	PrintList(l3);
	PrintList(l4);
	PrintList(l5);
	ListPrint(l5);
}

void TestList2()
{
	cout << "TestList2:" << endl;

	int arr[] = { 1,2,3,4 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));
	L.push_back(5);
	ListPrint(L);
	L.push_front(0);
	PrintList(L);

	L.pop_back();
	PrintList(L);
	L.pop_back();
	ListPrint(L);
}


void TestList3()
{
	cout << "TestList3:" << endl;
	int arr[] = { 1,2,3 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));
	auto pos = ++L.begin();
	cout << *pos << endl;

	//insert在pos位置之前加一个数据
	L.insert(pos, 4);
	PrintList(L);

	//在pos位置之前加上五个五
	L.insert(pos, 5, 5);
	PrintList(L);

	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L);

	L.erase(pos);
	PrintList(L);

	L.erase(L.begin(), L.end());
	PrintList(L);
}
void TestList4()
{
	list<Date> L;
	Date d(2019, 4, 19);
	L.push_back(d);
	L.emplace_back(2019, 4, 20);
	L.emplace_front(2019, 4, 18);
}

void TestList5()
{
	cout << "TestList5" << endl;
	int arr[] = { 1,2,3 };
	list<int> L1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintList(L1);
	//将L1中的元素个数增加到10个
	L1.resize(10);
	PrintList(L1);
	//将L1中的元素个数增加到20个  多处的元素用4填充
	L1.resize(20, 4);
	PrintList(L1);
	//将L1中的元素减少到5个
	L1.resize(5);
	PrintList(L1);

	vector<int> v{4, 5, 6};
	list<int> L2(v.begin(), v.end());
	PrintList(L2);

	L1.swap(L2);
	cout << "L1:";
	PrintList(L1);
	cout << "L2:";
	PrintList(L2);

	L2.clear();
	cout << L2.size() << endl;
}
//list的底层结构为带头结点的双向循环链表，
//因此在list中进行插入时是不会导致list的迭代
//器失效的，只有在删除时才会失效，并且失效的
//只是指向被删除节点的迭代器，其他迭代器不会受到影响。

void TestListIterator()
{
	cout << "TestListIterator:" << endl;
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));
	auto it = L.begin();
	while (it != L.end())
	{
		L.erase(it++);  //错误： L.erase(it);  ++it;
	}
}
int main()
{
	TestList1();
	TestList2();
	TestList3();
	TestList5();
	TestListIterator();
	system("pause");
	return 0;
}
