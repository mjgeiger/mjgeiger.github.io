//
//  os_MT_ex1.c
//  
//  EECE.4810/5730
//  Dr. Michael Geiger
//  2/12/18
//	In-class multithreading example program
//     Basic thread creation/termination
//
//  Code obtained from: https://computing.llnl.gov/tutorials/pthreads/samples/hello.c
//
/******************************************************************************
 * FILE: hello.c
 * DESCRIPTION:
 *   A "hello world" Pthreads program.  Demonstrates thread creation and
 *   termination.
 * AUTHOR: Blaise Barney
 * LAST REVISED: 08/09/11
 ******************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>			// Necessary for exit() function

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
	long tid;
	tid = (long)threadid;
	printf("Hello World! It's me, thread #%ld!\n", tid);
	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t = 0; t < NUM_THREADS; t++){
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	
	/* Last thing that main() should do--keeps main() alive to support
	    any outstanding threads until they complete */
	pthread_exit(NULL);
}