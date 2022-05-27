#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(void){
	pid_t pid;
	int status;
	int i;
	
	if( (pid=fork())==0){
		printf("i'm child : %d\n",getpid());
		for(i=0;i<4;i++){
			printf("child cnt: %d\n",i);
			sleep(i);
		}
	}else if(pid >0){
		printf("i'm parent : %d\n",getpid());
		printf("wait for child\n");
		wait(&status);
		for(i=0;i<4;i++){
			printf("parent cnt: %d\n",i);
			sleep(i);
		}
	}else{
		perror("fork()");
	}
	return 0;
}
