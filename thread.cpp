/*#include <iostream>
#include <thread>
#include <chrono>

void task() {
    std::cout << "Thread is running\n";
}

int main() {
    std::thread myThread(task); // Thread is in the "new" state
    // ...

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
}*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
int num = 1;

/*void* thread1(void* arg)
{
    while (num <= 10)
    {
		//wait
		sem_wait(&mutex);
		//critical section
		printf("\nEntered.. 1  ");
		
		if (num % 2 == 0) // even
			 printf ("- %d \n", num++);
			 
		//signal
		printf("Just Exiting...");
		sem_post(&mutex);
		sleep(2);
    }
}

void* thread2(void* arg)
{
    while (num <= 10)
    {
		//wait
		sem_wait(&mutex);
		//critical section
		printf("\nEntered.. 2 ");
		
		if (num % 2 != 0) // odd
			 printf ("- %d \n", num++);
			 
		//signal
		printf("Just Exiting...");
		sem_post(&mutex);
		
		sleep(2);
    }
}*/

void* printNumTh(void* arg)
{
	while(num <= 100)
	{
		sem_wait(&mutex);  // wait for  semaphore
		
		if (num%2 == 0)
		{
			printf("%d\n", num++); // even
		}
		else
		{
			printf("%d\n", num++); //odd
		}
		
		sem_post(&mutex); // release
	}
}


int main()
{
    sem_init(&mutex, 0, 1);  // sem count
    pthread_t t1,t2;
    pthread_create(&t1,NULL,printNumTh,NULL);
    //sleep(2);
    pthread_create(&t2,NULL,printNumTh,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}