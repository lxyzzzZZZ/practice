#include <iostream>
#include <time.h>
using namespace std;

//2.1命名空间的定义

//1.普通的命名空间

namespace N1	//N1为命名空间的名称
{
	//命名空间中的内容，既可以是定义的变量，也可以定义函数
	int a;
	int  Add(int left, int right)
	{
		return left + right;
	}
}

//2.命名空间可以嵌套

namespace N2
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N3
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

//3.同一个工程中允许存在多个相同名称的命名空间
//编译器最后会合成一个命名空间中

namespace N1
{
	int Mul(int left, int right)
	{
		return left + right;
	}
}

//注意：一个命名空间基于定义了一个新的作用域，命名空间中的所有内容都
//		局限于该命名空间中


//2.2命名空间的使用

//using N2::a;
//int main()
//{
//	cout << a <<endl;
//	system("pause");
//	return 0;
//}

//using namespace N1;
//int main(){
//	cout << a << endl;
//	system("pause");
//	return 0;
//}

//4.缺省函数

//全缺省参数

void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//半缺省参数

void TestFunc2(int a, int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//注意：半缺省参数必须从右到左依次给出，不能间隔给出
//		缺省参数不能在函数声明和定义中同时出现

//5.extern “c”
// 意思是告诉编译器，将该函数按照C语言规则来编译

//extern "C" int Add(int left, int right)
//{
//	;
//}
//int main()
//{
//	Add(1, 2); //报错：C语言无法这样初始化；
//	return 0;
//}

//6.引用

//引用不是新定义一个变量，而是给已存在的变量去一个别名，
//编译器不会为引用变量开辟内存空间，他和他用的变量共用同一块内存空间

//1.引用在定义时必须初始化
//2.一个变量可以拥有多个引用
//3.引用一旦引用一个实体，再不能引用其他实体
//4.引用与实体类型必须一致

//做参数
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

//做返回值

int& TestRefReturn(int& a)
{
	a += 10;
	return a;
}

int& Addx(int a, int b)
{
	int c = a + b;
	return c;
}

//int main()
//{
//	int& ret = Addx(1, 2);
//	Addx(3, 4);
//	cout <<"Addx is:"<< ret << endl;
//	system("pause");
//	return 0;
//}
//结果为：7
//注意：如果函数返回时，离开函数作用域后，其栈上空间已经还给系统，
//		因此不能用栈上的空间作为引用类型返回。如果以引用类型返回，
//		返回值的生命周期必须不受函数的限制(即比函数生命周期长)。

//传值、传引用效率比较

struct A
{
	int a[10000];
};

void TestFunC1(A a)
{
	;
}

void TestFunC2(A& a)
{
	;
}

void TestRefAndvalue()
{
	A a;
	//传值
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunC1(a);
	}
	size_t end1 = clock();

	//传引用
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunC2(a);
	}
	size_t end2 = clock();

	cout << "C1:" << end1 - begin1 << endl;
	cout << "C2:" << end2 - begin2 << endl;
}

//int main()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		TestRefAndvalue();
//	}
//	system("pause");
//	return 0;
//}

//通过上述代码的比较，发现传值和指针在作为传参以及返回值类型上效率相差很大

//6.6引用与指针的区别

//1.在语法概念上引用就是一个别名，没有独立的空间，和其引用的实体
//	共用一块空间
//2.在底层是实现上实际是有空间的，因为引用是按照指针方式来实现的


//7.内联函数

//7.1 概念

//以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数压栈的开销，
//内联函数提升程序运行的效率

//7.2 特性

//1. inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有循环 / 递归的函数不适宜使
//用作为内联函数。
//2. inline对于编译器而言只是一个建议，编译器会自动优化，如果定义为inline的函数体内有循环 / 递归等
//等，编译器优化时会忽略掉内联。
//3. inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找
//不到。

//8.auto关键字

int TestAuto()
{
	return 10;
}

//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	system("pause");
//	return 0;
//}

//8.2 auto的使用细则

//1.auto 与指针和引用结合起来使用

//用auto 声明指针类型，用auto和auto* 没有任何区别，但用auto声明引用类型时则必须加&

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	*a = 20;
//	*b = 30;
//	c = 40;
//	system("pause");
//	return 0;
//}

//2. 在同一行定义多个变量
//当在同一行声明多个变量时，这些变量必须是相同的类型，否则编译器将会报错，因为编译器实际只对第一个
//类型进行推导，然后用推导出来的类型定义其他变量。

void Testauto()
{
	auto a = 1, b = 2;
	//auto c = 3, d = 4.0;//编译失败
}

//8.3   auto不能作为函数的参数
//		auto不能直接用来声明数组

//9.基于范围的for循环

void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	for (auto& e : array)
	{
		e *= 2;
	}

	for (auto e : array)
	{
		cout << e << " ";
	}
	return;
}
