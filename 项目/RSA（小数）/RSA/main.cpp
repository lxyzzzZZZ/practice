
#include "RSA.h"

void test()
{
	RSA rsa;
	Key k = rsa.getKey();
	std::string strin;
	std::cin >> strin;
	std::vector<long> strecrept = rsa.ecrept(strin, k.ekey, k.pkey);
	std::string strout = rsa.decrept(strecrept, k.dkey, k.pkey);
	rsa.printInfo(strecrept);
	std::cout << strout.c_str() << std::endl;
}

void test2()
{
	RSA rsa;
	Key k = rsa.getKey();
	std::string filename;
	std::cout << "�����ļ�����" << std::endl;
	std::cin >> filename;
	rsa.ecrept(filename.c_str(),(filename + "ecrept.out.jpg").c_str(), k.ekey, k.pkey);
	rsa.decrept((filename + "ecrept.out.jpg").c_str(), (filename + "plain.out.jpg").c_str(), k.dkey, k.pkey);
}

//void test3()
//{
//	//mt19937:һ�������������
//	boost::random::mt19937 gen(time(nullptr));
//	std::cout << "random" << std::endl;
//	//ָ��������ķ�Χ 0 ~ (1<<786)
//	boost::random::uniform_int_distribution<bm::cpp_int> dist(0, bm::cpp_int(1) << 768);
//	std::cout << dist(gen) << std::endl;
//}
int main()
{
	//test();
	test();
	system("pause");
	return 0;
}