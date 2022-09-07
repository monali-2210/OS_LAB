#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(void){
	int n,fd[2];
	pid_t p;
	if(pipe(fd)==-1) exit(1);
	else printf("pipe created");
	if((p=fork())<0) exit(1);
}
