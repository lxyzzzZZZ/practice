#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//int main()
//{
//	int a = 80;
//	ofstream fout;
//	fout.open("test.out");
//	fout.write((const char*)&a, sizeof(int));
//	system("pause");
//	return 0;
//}

struct configInfo
{
	char _ip[50];
	int _port;
};
class configFile
{
public:
	configFile(const char* filename = "test.config")
	{
		_file = new char[strlen(filename)] + 1;
		strcpy(_file, filename);
	}

	void writeBinary(const configInfo& cinfo)
	{
		ofstream fout(_file);
		fout.write((char*)&cinfo, sizeof(cinfo));
	}

	void readBinary(configInfo& cinfo)
	{
		ifstream fout(_file, ifstream::out | ifstream::binary);
		fout.read((char*)&cinfo, sizeof(configInfo));
	}

	void writeTest(const configInfo& cinfo)
	{
		ofstream fout(_file);
		fout << cinfo._ip << endl;
		fout << cinfo._port << endl;
	}

	void readTest(configInfo& cinfo)
	{
		ifstream fout(_file);
		fout >> cinfo._ip;
		fout >> cinfo._port;

	}

	void test()
	{
		ifstream fin(_file);
		fin.seekg(0, fin.end);
		size_t len = fin.tellg();
	}
private:
	char* _file;
};
int main()
{
	configFile cfF;
	configInfo wfo;
	configInfo rfo;
	strcpy(wfo._ip, "127.0.0.1");
	wfo._port = 80;

	//二进制读写
	cfF.writeBinary(wfo);
	cfF.readBinary(rfo);
	cout << rfo._ip << endl;
	cout << rfo._port << endl;

	//文本读写
	cfF.writeTest(wfo);
	cfF.readTest(rfo);
	cout << rfo._ip << endl;
	cout << rfo._port << endl;

	system("pause");
	return 0;
}

