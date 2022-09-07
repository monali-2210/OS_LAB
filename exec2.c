#include<stdio.h>
#include<unistd.h>
int main(){
	 execlp("/bin/ls","ls","-l","-a",NULL);
	 printf("EXEC Failed\n");
	 return 0;
 }
