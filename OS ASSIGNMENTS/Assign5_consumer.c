# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdlib.h>

sem_t empty,full;
pthread_mutex_t mutex;
int buffer[5];
int count=0;

void *producer(void * arg){
	long int num=(long int)arg;
	
	// if empty =0 block , else continue to produce 
	sem_wait(&empty);
	
	pthread_mutex_lock(&mutex);
	
		//producer is producing data
		buffer[count]=rand()%10;
		printf("\n producer : %ld produce Item : %d ",(num+1)%10,buffer[count]);
		count++;
		sleep(1);

	pthread_mutex_unlock(&mutex); // released the lock on critical section 
	sem_post(&full);   // increament full value 
}

void *consumer(void * arg){
	long int num=(long int)arg;
	
	// if full =0 block , else continue to consume
	sem_wait(&full);
	
	pthread_mutex_lock(&mutex);

		//consumer is consuming data 
		count--;
		printf("\n Consumer : %ld consume Item : %d ",(num+1)%10,buffer[count]);
		sleep(1);

	pthread_mutex_unlock(&mutex); // released the lock on critical section 

	sem_post(&empty);   // increament the empty value
}


int main(){
	int np,nc; //number of producer and consumers
	
	pthread_t p[10] ,c[10]; //Thread variables .
	
	int i,j,k,l;
	
	printf("enter number of procducer  :\n");
	scanf("%d",&np);
	
	printf("enter number of Consumers  :\n");
	scanf("%d",&nc);
	
	//initialise samhore varaible 
	sem_init(&empty,0,5);
	sem_init(&full,0,0);
	
	pthread_mutex_init(&mutex,NULL);
	
	int a[5]={1,2,3,4,5};


	// create producer thread 
	for(i=0;i<np;i++){
		pthread_create(&p[i],NULL,producer,(void *)&a[i]);
	}
	
	
	// create consumer thread 
	for(j=0;j<nc;j++){
		pthread_create(&c[j],NULL,consumer,(void *)&a[j]);
	}
	
	for(k=0;k<np;k++)
		pthread_join(p[k],NULL);
	
	for(l=0;l<nc;l++)
		pthread_join(c[l],NULL);
		
			
	return 0;
	
}
