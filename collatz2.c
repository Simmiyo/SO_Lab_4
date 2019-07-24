#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
//#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
	pid_t pid=fork();
	if(pid<0)
	{
		perror("copil");
		return errno;
	}
	else if(pid==0)
	{
		int n=atoi(argv[1]);
		printf("%d: ",n);
		while(n>1)
		{
			printf("%d ",n);
			if(n%2==0)
			   n=n/2;
			else
			   n=3*n+1;
		}
		printf("1\n");

	}
	else
	{
		wait(0);
		printf("Child %d finished\n",getpid());
	}
	return 0;
}
