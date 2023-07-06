#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// mutex for locking
pthread_mutex_t mutex;

// Method which will be called by the threads 
// and print the series
void *increment(void *input)
{       
        int *n = (int *) input;
        // Locks the thread
//      pthread_mutex_lock(&mutex);
        
        int i;
        for(i=1; i<=*n; i++) {
                printf("%d, ", i);
        }
        
        // Unlocks the thread
//      pthread_mutex_unlock(&mutex);
        return NULL;
}


// Main function
int main()
{
        
        // Variable defined
        int n;
        // N are taken as input
        printf("N: ");
        scanf("%d", &n);
        
        // Array of thread is defined
        pthread_t *thread_id = malloc(sizeof(pthread_t) * n);
        
        // Thread Locking initialised
//      pthread_mutex_init(&mutex, NULL);
        
        int i;
        // Thread is called t times and value of n is passed as argument
        for(i=0; i<n; i++){
                pthread_create(&thread_id[i], NULL, increment, &n);
        }

        // Thread Joining
        for(i=0; i<n; i++){
                pthread_join(thread_id[i], NULL);
        }
        
        // Thread Locking ends
//      pthread_mutex_destroy(&mutex);

        return 0;
}