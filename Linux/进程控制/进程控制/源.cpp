//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//#include <sys/wait.h>
//
//#include <stdio.h>
//int main()
//{
//	pid_t pid;
//	printf("before: pid = %d \n", getpid());
//	if ((pid = fork()) == -1)
//	{
//		printf("errno\n");
//	}
//	printf("after: pid = %d,fork return %d\n", getpid(), pid);
//	sleep(1);
//	return 0;
//}
//
//
//int glob = 100;
//
//int main(void)
//{
//	pid_t pid;
//
//	printf("%d\n", glob);
//	if ((pid = vfork()) == -1)
//	{
//		exit(0);
//	}
//	if (pid == 0)
//	{
//		sleep(5);
//		glob = 200;
//		printf("child glob = %d \n", glob);
//		exit(0);
//	}
//	else
//	{
//		printf("parent glob %d\n", glob);
//	}
//
//	return 0;
//}
//
//
//
//
//int main()
//{
//	pid_t pid;
//	pid = fork();
//	if (pid < 0)
//	{
//		printf("fork error\n");
//	}
//	else if (pid == 0)
//	{
//		printf("child is run ,pid = %d\n", getpid());
//	}
//	else
//	{
//		int status = 0;
//		pid_t ret = waitpid(-1, &status, 0);
//		printf(" wait \n");
//		if (WIFEXITED(status) && ret == pid)
//		{
//			printf("wait child 5s success, child return code is %d\n"
//				, WEXITSTATUS(status));
//		}
//		else
//		{
//			printf("wait child failed, return \n");
//			return 1;
//		}
//	}
//	return 0;
//}
//
//
//
//
//int main()
//{
//	pid_t pid;
//	if ((pid = fork()) == -1)
//	{
//		perror("fork"), exit(1);
//	}
//
//	if (pid == 0)
//	{
//		sleep(25);
//		exit(10);
//	}
//	else
//	{
//		int st;
//		int ret = wait(&st);
//		if (ret > 0 && (st & 0x7F) == 0)
//		{
//			printf("child exit code : %d\n", (st >> 8) & 0xFF);
//		}
//		else if (ret > 0)
//		{
//			printf("sig code: %d\n", st & 0x7F);
//		}
//	}
//	return 0;
//}
//
//
//
//
//int main()
//{
//	pid_t pid;
//	pid = fork();
//	if (pid < 0)
//	{
//		printf("fork error\n");
//		return 1;
//	}
//	else if (pid == 0)
//	{
//		printf("child is run ,pid = %d\n", getpid());
//		sleep(5);
//		exit(1);
//	}
//	else
//	{
//		int status = 0;
//		pid_t ret = 0;
//		do
//		{
//			ret = waitpid(-1, &status, WNOHANG);
//			if (ret == 0)
//			{
//				printf("child is running\n");
//			}
//			sleep(1);
//		} while (ret == 0);
//		printf(" wait \n");
//		if (WIFEXITED(status) && ret == pid)
//		{
//			printf("wait child 5s success, child return code is %d\n"
//				, WEXITSTATUS(status));
//		}
//		else
//		{
//			printf("wait child failed, return \n");
//			return 1;
//		}
//	}
//	return 0;
//}
//
//
//
//
//char * argv[8];
//int argc = 0;
//
//void do_parse(char *buf)
//{
//	int i;
//	int status = 0;
//	for (argc = i = 0; buf[i]; i++)
//	{
//		if (!isspace(buf[i]) && status == 0)
//		{
//			argv[argc++] = buf + i;
//			status = 1;
//		}
//		else if (isspace(buf[i]))
//		{
//			status = 0;
//			buf[i] = 0;
//		}
//	}
//	argv[argc] = NULL;
//}
//
//void do_execute(void)
//{
//	pid_t pid = fork();
//
//	switch (pid)
//	{
//	case -1:
//		perror("fork");
//		exit(EXIT_FAILURE);
//		break;
//	case 0:
//		execvp(argv[0], argv);
//		perror("execvp");
//		exit(EXIT_FAILURE);
//	default:
//	{
//		int st;
//		while (wait(&st) != pid);
//	}
//	}
//}
//
//int main()
//{
//	char buf[1024] = {};
//	while (1)
//	{
//		printf("myshell > ");
//		scanf("%[^\n]%*c", buf);
//		do_parse(buf);
//		do_execute();
//	}
//	return 0;
//}