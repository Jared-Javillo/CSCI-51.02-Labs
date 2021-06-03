#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <unistd.h> 

using namespace std;

void printState(char state);

int main( int argc, char* argv[])
{
    // Semaphore Initialization
    int semId;
    key_t semKey = 1234;
    int semFlag = IPC_CREAT | 0666;
    int nSems = 1;

    semId = semget( semKey, nSems, semFlag );
    if( semId == -1 )
    {
        perror( "semget" );
        exit( 1 );
    }

    int nOperations = 2;
    struct sembuf sema[nOperations];

    sema[0].sem_num = 0; // Use the first semaphore in the semaphore set
    sema[0].sem_op = 0; // Wait if semaphore != 0
    sema[0].sem_flg = SEM_UNDO; // See slides

    sema[1].sem_num = 0; // Use the first semaphore in the semaphore set
    sema[1].sem_op = 1; // Increment semaphore by 1
    sema[1].sem_flg = SEM_UNDO | IPC_NOWAIT; // See slides

    int opResult = semop( semId, sema, nOperations );

    // Shared Memory A (Text) Initialization
    int shmIdA;
	key_t shmKeyA = 6666;
	int shmSizeA = atoi(argv[2]);
	int shmFlagsA = IPC_CREAT | 0666;
	char* sharedMemA;
	
    shmIdA = shmget( shmKeyA, shmSizeA, shmFlagsA );
	sharedMemA = (char*) shmat( shmIdA, NULL, 0 );
    
    if( ((int*)sharedMemA) == (int*)-1 )
    {
        perror( "shmop: shmat failed for Mem A" );
    }

    //Shared Memory B (States) Initialization
	int shmIdB;
	key_t shmKeyB = 7777;
	int shmSizeB = atoi(argv[2]);
	int shmFlagsB = IPC_CREAT | 0666;
	char* sharedMemB;

	shmIdB = shmget( shmKeyB, shmSizeB, shmFlagsB );
	sharedMemB = (char*) shmat( shmIdB, NULL, 0 );

    if( ((int*)sharedMemB) == (int*)-1 )
    {
        perror( "shmop: shmat failed for Mem B" );
    }

	char state = '1';

    //Output Initialization
	const int bufferSize = 50;
	char* writer = new char[bufferSize];
	ofstream outputText;
	cout << "\n";
	outputText.open( argv[1], ios::out );
	outputText.close();
	outputText.open( argv[1], ios::out | ios::app );

    //read memory A then writes to output txt
    if( opResult != -1 )
    {
       while (true){	
            printState(state);
            // Get state from Memory B
			if ( state == 'R' || state == 'W' || state == '1')
            {
				strcpy( writer, sharedMemB );
				state = writer[0];
				sleep(1);
				continue;
			}
            // Pasting
			else if ( state == '-' ){	
				memset( writer, 0, 255 );
				strcpy( writer, sharedMemA );
				outputText << writer;
				state = 'R';
				sharedMemB[0] = state;
				memset( sharedMemA, 0, 255 );
				sleep(1);
			}
            //Pasting is Done
			else if ( state == '0' ){
				memset( writer, 0, 255 );
				strcpy( writer, sharedMemA );
				outputText << writer;
				outputText.close();
				memset( sharedMemA, 0, 255 );
                cout << "Copy successful!\n";
				exit(1);
			}
            
			sleep(1);
			nOperations = 1;

			sema[0].sem_num = 0;
			sema[0].sem_op = -1;
			sema[0].sem_flg = SEM_UNDO | IPC_NOWAIT;

			opResult = semop( semId, sema, nOperations );

			if ( opResult == -1 ){
				perror( "Semaphore not released" );
			}
       }
    }
    else
    {
        perror( "semop (increment)" );
    }

    return 0;
}

//Print States according to char
void printState(char state){
    if (state == '-')
    {
        cout << "Current State: Waiting\n";
    }
    else if (state == 'R')
    {
        cout << "Current State: Reading \n";
    }
    else if (state == 'W')
    {
        cout << "Current State: Writing\n";
    }
    else if (state == '0')
    {
        cout << "Current State: Finished\n";
    }
    else if (state == '1')
    {
        cout << "Current State: Ready\n";
    }
    
}