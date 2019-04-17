#include <iostream>


using namespace std;

int main()
{
	int n = 9;
	cin >> n;
	for (int i = 1; i <= 1000; i*=2)
	{
		for (int j = i / 2; j <= i; j++)
		{
			if (j > n)
			{
				cout << j-1 << endl;
				goto text;
			}
		}

	}
	text:
	system("pause");
	return 0;
}
//#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//
////获取进程标识符
//int main()
//{
//	printf("%d\n", getpid());
//	printf("%d\n", getppid());
//	return 0;
//}
//

//创建子进程
//int main()
//{
//	int ret = fork();
//	printf("hello proc : %d!, ret: %d\n", getpid(), ret);
//	sleep(1);
//	return 0;
//}


//
//int fun1()
//{
//	int ret = fork();
//	if (ret < 0)
//	{
//		perror("fork");
//		return 1;
//	}
//	else if (ret == 0)
//	{
//		printf(" i am child : %d, ret : %d\n", getpid(), ret);
//	}
//	else
//	{
//		printf(" i am father : %d, ret : %d\n", getpid(), ret);
//	}
//	sleep(1);
//	return 0;
//}
//int fun2()
//{
//	pid_t id = fork();
//	if (id < 0)
//	{
//		perror("fork");
//		return 1;
//	}
//	else if (id > 0)
//	{
//		printf("parent[%d] is sleeping...\n", getpid());
//		sleep(30);
//	}
//	else
//	{
//		printf("child[%d] is begin Z...\n", getpid());
//		sleep(5);
//		exit(EXIT_SUCCESS);
//	}
//	return 0;
//}
//
//
//
//int fun3()
//{
//	pid_t id = fork();
//	if (id < 0)
//	{
//		perror("fork");
//		return 1;
//	}
//	else if (id == 0)
//	{
//		printf("i am childe,pid : %d\n", getpid());
//		sleep(10);
//	}
//	else
//	{
//		printf("i am parent,pid : %d\n", getpid());
//		sleep(5);
//		exit(0);
//	}
//	return 0;
//}
//
//
//
//
//int main()
//{
//	//return fun1();
//	//return fun2();
//	return fun3();
//}
