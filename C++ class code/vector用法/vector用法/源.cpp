#include <iostream>
#include <vector>


using namespace std;

//int main()
//{
//	vector<int> first;
//	vector<int> second(4, 100);
//	vector<int> third(second.begin(), second.end());
//	vector<int> fourth(third);
//	
//	int myints[] = { 16,2,77,29 };
//	vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
//	for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//	{
//		cout << ' ' << *it;
//		cout << '\n';
//
//	}
//	system("pause");
//
//	return 0;
//}

//void PrintVector(const vector<int>& v)
//{
//	vector<int>::const_iterator it = v.cbegin();
//	while (it != v.cend())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(1);
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	PrintVector(v);
//
//	system("pause");
//	return 0;
//}

int main()
{
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
	system("pause");
	return 0;
}


