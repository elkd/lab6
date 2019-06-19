#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
int fdr, fdw;
char buffer;
void read_write();
int main(int argc, char *argv[])
{
	pid_t pid;
	if(argc !=3)
	{
		printf("Error!\n");
		printf("\t Usage: %s readfile writefile\n",argv[0]);
		exit(0);
	}
	if ((fdr = open(argv[1], O_RDONLY)) ==-1)
	{
		exit(1);	}
	if ((fdw = open(argv[2],0666)) ==-1)
	{	exit(1);	}
	
	pid = fork();
	if (pid>0)
	{	read_write();	}
	else 
	{	read_write(); 	}
	return 0;
}
void read_write()
{
	while (1 )
	{
		if (read(fdr,&buffer,1) !=1 )
		{	break;	}
		else
		{ 	write(fdw,&buffer,1);	}
	}
}



