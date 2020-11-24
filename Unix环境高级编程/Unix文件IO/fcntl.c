#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int val;

	if (argc != 2)
		printf("usage :a.out <description>\n");
	if (val = fcntl(atio(argv[1]), F_GETFL, 0) < 0)
		printf("fcntl error for fd %d", atoi(argv[1]));
	switch (val & O_ACCMODE)
	{
	case O_WRONLY:
		printf("write only\n");
		break;
	case O_RDONLY:
		printf("read only\n");
		break;
	case O_RDWR:
		printf("read write\n");
		break;
	default:
		printf("Unknow access mode\n");
		break;
	}

	if (val & O_APPEND)
		printf(",append");
	if (val & O_NONBLOCK)
		printf(", nonblocking");
	if (val & O_SYNC)
		printf(", synchronous");
	return 0;
}