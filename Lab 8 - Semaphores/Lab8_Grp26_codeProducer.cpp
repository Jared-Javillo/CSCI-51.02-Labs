#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h> 
#include <string>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>

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

	char state = 'R';
    			
	const int bufferSize = 50;
	char reader[bufferSize];
	fstream inputText;
	
	inputText.open( argv[1], ios::in );

    //Write contents to memory A
    if( opResult != -1 )
    {
         while ( true ){
            printState(state);
            //When code reaches the last line of the txt file
			if ( inputText.eof() ){
				state = '0';
				sharedMemB[0] = state;
				cout << "Writing File Finished\n";
			}
            
            //Get state from B
			if ( state == '-' || state == 'W' || state == '1')
            {
				strcpy( reader, sharedMemB );
				state = reader[0];
				sleep(1);
				continue;	
			}
            //Write contents to memory A
            else if ( state == 'R' ){
				sharedMemB[0] = state;
				memset( reader, 0, 255 );
				inputText.read( reader, bufferSize );
				memset( sharedMemA, 0, 255 );
				strcpy( sharedMemA, reader );
				state = '-';
				sharedMemB[0] = state;
				sleep(1);
            }
            //Writing is Finished 
			else if ( state == '0' ){
				memset( sharedMemA, 0, 255 );				
				inputText.close();
				exit(1);
			}
            

			sleep(1);

			nOperations = 1;

			sema[0].sem_num = 0;
			sema[0].sem_op = -1;
			sema[0].sem_flg = SEM_UNDO | IPC_NOWAIT;

			opResult = semop( semId, sema, nOperations );

			if ( opResult == -1 ){
				perror( "Semaphore not released " );
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