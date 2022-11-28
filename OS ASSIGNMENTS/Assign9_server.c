#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<string.h>

int main()
{

	void * shared_memory;
	char str[100];

	// CREATE KEY
	key_t k = 1234;


	// CREATE SHARED MEMORY
	int shmid = shmget(k, 1024, 0666 | IPC_CREAT);
	

	// ATTATCH MEMORY
	shared_memory = shmat(shmid,NULL,0); 
	

	// INPUT DATA TO SHARE
	printf("Write data :");
	fgets(str);


	strcpy(shared_memory,str);
	printf("data written in memory : %s \n",(char *)shared_memory);
	

	// DETTATCH MEMORY
	shmdt(shared_memory);
	

	return 0;
}

