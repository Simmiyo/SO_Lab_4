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
		char *argv1[]={"/bin/ls",NULL};
		if(execve("/bin/ls",argv1,NULL)<0)
		{
			perror("execve");
			return errno;
		}
	}
	else
	{
		printf("My PID =  %d     Child's PID =  %d\n",getppid(),getpid());
		wait(0);//waitpid(-1,0,0);
		printf("Child %d finished\n",getpid());
	}
	return 0;
}
