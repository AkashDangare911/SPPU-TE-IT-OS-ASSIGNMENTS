# include <stdio.h>
# include <pthread.h>

pthread_mutex_t wr,mutex;
int a=10,readcount=0;

void * reader(void * arg)
{
    long int num =(long int)arg;

    pthread_mutex_lock(&mutex);
    readcount++;
    pthread_mutex_unlock(&mutex);

    if (readcount==1)
        pthread_mutex_lock(&wr);
       
      
     printf("\n Reader %ld is in critical section",num); 

    printf("\n Reader %ld reading data %d ",num,a);
    sleep(1);
    
    pthread_mutex_lock(&mutex);
    readcount--;
    pthread_mutex_unlock(&mutex);

    if(readcount==0)
        pthread_mutex_unlock(&wr);
        
     printf("\n Reader %ld has left critical section",num); 

}

void * writer(void *arg){
    long int num =(long int)arg;

    // lock wr varaible to enter cs
    pthread_mutex_lock(&wr);

    printf("\n Writer %ld is in critical section",num); 

    printf("\n Writer %ld have written data as %d ",num,++a);
    sleep(1);

    pthread_mutex_unlock(&wr);
    printf("\n Reader %ld has left critical section",num); 

}

int main(){
    pthread_t r[10],w[10];

    long int i,j;
    int nor,now;

    //initialize mutex var
    pthread_mutex_init(&wr,NULL);
    pthread_mutex_init(&mutex,NULL);


    printf("Enter the number of reader :\n");
    scanf("%d",&nor);
    printf("Enter the number of writer :\n");
    scanf("%d",&now);


    // create reader and writer thread
    for ( i = 0; i < nor; i++)
        pthread_create(&r[i],NULL,reader,(void *)i);

    for (j = 0; j < now; j++)
        pthread_create(&w[j],NULL,writer,(void *)j);


    // join the threads
    for ( i = 0; i < nor; i++)
    {
        pthread_join(r[i],NULL);
    }
    for ( j = 0; j < now; j++)
    {
        pthread_join(w[i],NULL);
    }
    

    return 0;
}
