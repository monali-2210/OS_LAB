#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int file_desc = open("dup.txt", O_WRONLY | O_APPEND);
	if(file_desc < 0){
		printf("Error opening the file\n");
	}
	int copy_desc = dup(file_desc);
	write(copy_desc, "This will be the output to the file named dup.txt\n", 46);

	write(file_desc, "This will also be the output to the file named dup.tx\n", 51);
	return 0;
}
