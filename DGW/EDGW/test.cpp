#include <stdio.h>
#include <sys/types.h>
#include <syscall.h>
#define _GNU_SOURCE
       #include <unistd.h>
       #include <sys/syscall.h>
       #include <sys/types.h>

int main(int argc,char ** argv)
{
	printf("%d\r\n",syscall(SYS_gettid));


	double daa = 22.13456;

	double daa2 = 0;

	int iaa = daa2=daa*60*30000;

	printf("daa = %f\r\ndaa2= %f\r\niaa = %i\r\n",daa,daa2,iaa);

	return 0;

}


