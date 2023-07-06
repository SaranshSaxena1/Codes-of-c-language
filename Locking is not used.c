#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// counter defined globally
int counter = 0;

// Method which will be called by the threads 
// and will increment counter by n
void *increment(void *input)
{       
        int *n = (int *) input;
        counter += *n;
        return NULL;
}


// Main function
int main()
{
        
        // Variables defined
        int t, n;
        // T and N are taken as input
        printf("T: ");
        scanf("%d", &t);
        printf("N: ");
        scanf("%d", &n);
        
        // Array of thread is defined
        pthread_t *thread_id = malloc(sizeof(pthread_t) * t);
        int i;
        // Thread is called t times and value of n is passed as argument
        for(i=0; i<t; i++){
                pthread_create(&thread_id[i], NULL, increment, &n);
        }
        // Thread joining
        for(i=0; i<t; i++){
                pthread_join(thread_id[i], NULL);
        }
        printf("Counter = %d", counter);

        return 0;
}