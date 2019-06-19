#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(void)
{
    int n,fd[2];
    pid_t pid;
    char line[50];
    if ( pipe(fd) <0)
    {
        printf("pipe error\n");
        exit(1);
    }
    if( (pid =fork()) <0)
    {
        printf("fork error\n");
        exit(1);
    }
    else if(pid >0)
    {
        close(fd[0]);
        printf("Parent writing to child\n");
        write(fd[1],"Hello child process\n",20);
    }
    else
    {
        close(fd[1]);
        n=read(fd[0],line,21);
        printf("Child n=%d String = %s\n",n,line);
        write(STDOUT_FILENO,line,n);
    }
    exit(0);
}
