#include <stdio.h>
#include <linux/ioctl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
extern void code_to_execute(void);
extern unsigned long long data_flag;
int main(int argc, char* argv[]) {
	int a;
	printf("address on stack is %p\n", &a);
	printf("data_flag before ioctl =  %llu\n", data_flag);
	int fd = open("/dev/query", O_RDWR);
	if (fd == -1) { 
		printf("open failed with errno = %d\n", errno);
		return -1;
	}
	int res;
	res = ioctl(fd, 0, (unsigned long) code_to_execute);
//	code_to_execute();
	printf("ioctl returned = %d\n", res);
	if (res != 0)
		printf("errno = %d\n", errno);
	printf("data_flag after ioctl =  %llu\n", data_flag);
	return 0;
}
