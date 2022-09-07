#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int pav=1;
	pid_t p=fork();S
	if(p==0){
		if(pav==1){
			printf("Variable shared with child process\n");
		}
		return 1;
	}	
}
