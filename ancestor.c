#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
	int a,n;
	scanf("%d %d",&a,&n);
l:
	if(a==0){
		return 0;//child process
	}
	for(int i=0;i<n;i++){
		pid_t p=fork();
		pid_t par= getppid();
		pid_t ch=getpid();
		if(p>0) waitpid(p,0,0);
		else{
			printf("parent: %d child: %d\n",par,ch);
			a--;
			goto l;
		}
	}
	return 0;
}
