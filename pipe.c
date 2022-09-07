#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(void){
	int n,fd[2];
	pid_t pid;
	char line[20];
	if(pipe(fd) == -1) exit(1);
	else printf("PIPE created by parent successfully\n");
	if((pid = fork()) < 0) exit(1);
	else if(pid>0){
		close(fd[0]);
		write(fd[1],"hello world\n",12);	
	}else{
		close(fd[1]);
		n=read(fd[0],line,20);
	//	line[n]='\0';
	}
	return 1;
}
