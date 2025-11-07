#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
void *thread_1(void *p)
{
	while(1)
	{
		printf("in function\n");
		sleep(1);
	}
}
int main()
{
	pthread_t t1;
	pthread_create(&t1,0,thread_1,0);
        while(1)
	{
		printf("in main\n");
		sleep(1);
	}
}
