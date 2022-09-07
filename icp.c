#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int comp(const void* a, const void* b){ return(*(int*)a - *(int*)b);
}

int main(){
	int n,fd[2];
	pid_t pid;
	int arr[5]={7,2,9,5,1};
	if(pipe(fd)==1) exit(1);
	else printf("PIPE created by parent\n");

	if((pid=fork())<0) exit(1);
	else if(pid>0){
		close(fd[0]);
		write(fd[1], arr,5*sizeof(int));
		
	}
	else{
		close(fd[1]);
		n= read(fd[0], arr, 5*sizeof(int));
		qsort(arr,5,sizeof(int),comp);
		for(int i=0;i<5;i++){
			printf("\n%d", arr[i]);
		}
	}
	return 0;
}
