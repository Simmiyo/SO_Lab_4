#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
//#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
	printf("Starting Parent %d\n",getpid());
	for(int i=1;i<argc;i++)
	{
		pid_t pid=fork();
		if(pid<0)
		{
			perror("copil");
			return errno;
		}
		else if(pid==0)
		{
			int n=atoi(argv[i]);
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
			printf("Done Parent %d   Me %d\n",getppid(),getpid());
			exit(0);
		}
	}
	waitpid(-1,0,0);
	return 0;
}
