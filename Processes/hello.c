#include <stdio.h>


int fn(char *buf)
{
	buf[0] = 'A';
	return 1;
}

int main()
{
	char buf[20];
	memset(buf, 0, sizeof(buf));
	fn(buf);
	printf("Pid = %u and PPID = %u\n", getpid(), getppid());
	for (int i = 0; i < 10; i++)
	{
		printf("Hello World\n");
		sleep(1);
	}
	printf("%s\n", buf);
	return 0;
}
