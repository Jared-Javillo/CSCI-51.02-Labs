#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//sources: https://www.youtube.com/watch?v=1ks-oMotUjc

int threadID = 1;
void* function_thread(void* arg)
{
    //Get input from thread_create
    long long output = 0;
    long long *limit_ptr = (long long*) arg;
    long long old = *limit_ptr;

    // If Even  
    if (threadID % 2 != 0)
    {
        output = old*old*old;
    }

    //If odd
    else
    {
        output = -old;
    }
    threadID++;
    
    printf("%lld(old) has been replaced with %lld(new)\n", old, output);

    pthread_exit(0);
}

int main(int argc, char **argv)
{
    //If arguments are less than or equal to 1
    if (argc <= 1 )
    {
        printf("ERROR\nExample: %s <num> <num1> <num2> <num3> ... <numN>\n", argv[0]);
        exit(-1);
    }

    //Dynamically creates Threads based on argument number
    for (int i = 1; i < argc; i++)
    {
        //Instatiate attributes for thread
        long long limit = atoi(argv[i]);
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        //Thread Create
        pthread_create(&tid, &attr,function_thread, &limit);

        //Thread Stop when finished
        pthread_join(tid,NULL);
    }

}