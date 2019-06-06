#include <iostream>
#include <string>
using namespace std;


//int main()
//{
//	string str("3456789JQKA");
//
//	string str1("AAAA");
//	string str2("34");
//
//	cout << str.find(str1[0]) << endl;
//	cout << str.find(str2[0]) << endl;
//	system("pause");
//	return 0;
//}
int main()
{
	string str;
	getline(cin, str);
	string str1, str2, ret1, ret2;
	string ret("345678910JQKA2");
	int flag = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			flag = 1;
			continue;
		}
		if (flag == 0)
		{
			ret1.push_back(str[i]);
			if (str[i] == ' ')
				continue;
			else
				str1.push_back(str[i]);
		}
		else
		{
			ret2.push_back(str[i]);
			if (str[i] == ' ')
				continue;
			else
				str2.push_back(str[i]);
		}
	}
	if (ret1 == "joker JOKER" || ret2 == "joker JOKER")
	{
		cout << "joker JOKER" << endl;
		return 0;
	}
	if (str1.size() != str2.size())
	{
		if (str1.size() == 4)
		{
			cout << ret1.c_str() << endl;
			return 0;
		}
		else if (str2.size() == 4)
		{
			cout << ret2.c_str() << endl;
			return 0;
		}
		else if (str1.size() == 1 && str2.size() == 5 && (str2[0] == 'j' || str2[0] == 'J'))
		{
			cout << ret2.c_str() << endl;
			return 0;
		}
		else if (str2.size() == 1 && str1.size() == 5 && (str1[0] == 'j' || str1[0] == 'J'))
		{
			cout << ret1.c_str() << endl;
			return 0;
		}
		cout << "ERROR" << endl;
		return 0;
	}
	else
	{
		if (ret.find(str1[0]) > ret.find(str2[0]))
		{
			cout << ret1.c_str() << endl;
			return 0;
		}
		else
		{
			cout << ret2.c_str() << endl;
			return 0;
		}
	}
	system("pause");
	return 0;
}
//int main()
//{
//	string str;
//	getline(cin, str);
//	string str1, str2, ret1, ret2;
//	string ret("345678910JQKA2");
//	int flag = 0;
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		if (str[i] == '-')
//		{
//			flag = 1;
//			continue;
//		}
//		if (flag == 0)
//		{
//			ret1.push_back(str[i]);
//			if (str[i] == ' ')
//				continue;
//			else
//				str1.push_back(str[i]);
//		}
//		else
//		{
//			ret2.push_back(str[i]);
//			if (str[i] == ' ')
//				continue;
//			else
//				str2.push_back(str[i]);
//		}
//	}
//	cout << str1.c_str() << " " << str2.c_str() << endl;
//	cout << ret1.c_str() << " " << ret2.c_str() << endl;
//	system("pause");
//	return 0;
//}
//
//bool is_perfectnum(int n)
//{
//	int sum = 0;
//	for (int i = 1; i < n; i++)
//	{
//		if (n % i == 0)
//			sum += i;
//	}
//	if (sum == n)
//		return true;
//	return false;
//}
//
//int main()
//{
//	int count;
//	while (cin >> count)
//	{
//		int n = 0;
//		for (int i = 1; i <= count; i++)
//		{
//			if (is_perfectnum(i) == true)
//				n++;
//		}
//		cout << n << endl;
//	}
//	system("pause");
//	return 0;
//}




//int main()
//{
//	string str;
//	int n = 5;
//	while (n--)
//	{
//		str.push_back('\0');
//	}
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		cout << *it << 1 << endl;
//		it++;
//	}
//	//const int a = 10;
//	//int* p = (int*)(&a);
//	//*p = 20;
//	//cout << a << " " << *p << endl;
//	system("pause");
//	return 0;
//}




#include <iostream>
#include <string>

using namespace std;
int num(string s) {
	int res = 1;
	int n = s.find(' ');
	while (n != -1) {
		s = s.substr(n + 1);
		n = s.find(' ');
		res++;
	}
	return res;
}
int main() {
	string s;
	string p = "345678910JQKA2";
	while (getline(cin, s)) {
		int n = s.find('-');
		string s1 = s.substr(0, n);
		string s2 = s.substr(n + 1);
		string m = "joker JOKER";
		if (s1.find(m) != -1 || s2.find(m) != -1) {
			cout << m << endl;
			continue;
		}
		int n1 = num(s1), n2 = num(s2);

		if (n1 == 4 && n2 != 4) {
			cout << s1 << endl;
		}
		else if (n1 != 4 && n2 == 4) {
			cout << s2 << endl;
		}
		else if (n1 != n2) {
			cout << "ERROR" << endl;
		}
		else if (n1 == 1) {
			if (p.find(s1) < p.find(s2)) {
				cout << s2 << endl;
			}
			else {
				cout << s1 << endl;
			}
		}
		else {
			int p1 = p.find(s1.substr(0, s1.find(' ')));
			int p2 = p.find(s2.substr(0, s2.find(' ')));
			if (p1 < p2) {
				cout << s2 << endl;
			}
			else {
				cout << s1 << endl;
			}
		}
	}
	return 0;
}