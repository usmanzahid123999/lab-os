#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
 
void *printMessage(void *msg);
 
void main()
{
	pthread_t thread1, thread2;
	char *message = "Hello!";
 
	pthread_create(&thread1, NULL, printMessage, (void*) message);
	pthread_create(&thread2, NULL, printMessage, (void*) message);
	sleep(3);
 
printf("\nID of first thread is %lu\nID of process is %d\n", (unsigned long) thread1,getpid());
	printf("\nID of second thread is %lu\nID of process is %d\n", (unsigned long) thread2,getpid());}
 
void *printMessage(void *msg)
{
	char *message;
   	message = (char *) msg;
	printf("\n%s\n", message);

	pthread_exit(0);
}
