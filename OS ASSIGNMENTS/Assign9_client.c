#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include<string.h>

int main()
{
	void *shared_memory;
	int shmid = shmget((key_t)2345, 1024, 0666 );

	shared_memory = shmat(shmid,NULL,0); // attach the shared Memory

	printf("data from shared_memory  : %s \n", (char *)shared_memory);

	// detach from shared memory
	shmdt(shared_memory);

	return 0;
}





#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	void * shared_memory;
	int shmid = shmget((key_t)1234,1024,0666);

	shared_memory = shmat(shmid,NULL,0);

	printf("The data from shared memery is -> %s",(char *)shared_memory);

	shmdt(shared_memory);

	return 0;
}














