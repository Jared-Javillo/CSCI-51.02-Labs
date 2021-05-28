#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

//sources: https://www.youtube.com/watch?v=1ks-oMotUjc
//         https://www.geeksforgeeks.org/c-program-for-factorial-of-a-number/

long double SumOutput;

//Struct for input
typedef struct s_input 
{
    int numThreads;
    int threadID;
    long double toSin;
} input;

//Gets Factorial
long double factorial(long double n)
{
    long double res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

//Sin method
void* function_thread(void* arg)
{
    //Get Inputs
    long double threadSum = 0;
    input *limit_ptr = (input*) arg;
    input old = *limit_ptr;

    while(true)
    {
        //Calculate Term
        long double x = pow(old.toSin,old.threadID+(old.threadID-1));
        long double y = factorial(old.threadID+(old.threadID-1));
        long double z = x/y;

        //Add to global variable
        if (old.threadID % 2 == 0)
        {
            SumOutput -= z;
        }
        else
        {
            SumOutput += z;
        }
        
        //Calculation for next term for thread
        old.threadID = old.numThreads + old.threadID;

        //break if z < 10^-16
        if (z < pow(10,-16))
        {
            break;
        }
    }

    pthread_exit(0);
}

int main(int argc, char **argv)
{
    //Initialize input struct
    input argInput;
    int N = atoi(argv[1]);
    long double in = strtold(argv[2], NULL);
    argInput.numThreads = N;
    argInput.toSin = in;

    //If arguments are not 3
    if (argc != 3 )
    {
        printf("ERROR\nExample: %s <num> <num1>\n", argv[0]);
        exit(-1);
    }

    //Dynamically creates Threads based on argument number
    for (int i = 1; i <= N; i++)
    {
        //Instatiate attributes for thread
        argInput.threadID = i;
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        //Thread Create
        pthread_create(&tid, &attr,function_thread, &argInput);

        //Thread Stop when finished
        pthread_join(tid,NULL);
    }

    //Output
    printf("%Lf\n",SumOutput);
}