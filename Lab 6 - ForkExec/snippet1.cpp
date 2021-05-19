#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(void){
    if( fork() == 0 ) {
        wait(NULL);
        cout << "PID: " << getpid()<<" PPID: "<< getppid() << "\n";
    }
    else if( fork() == 0 ) {
        wait(NULL);
        cout << "PID: " << getpid()<<" PPID: "<< getppid() << "\n";
    }
    else if( fork() == 0 ) {
        wait(NULL);
        cout << "PID: " << getpid()<<" PPID: "<< getppid() << "\n";
    }
    else if( fork() == 0 ) {
        wait(NULL);
        cout << "PID: " << getpid()<<" PPID: "<< getppid() << "\n";
    }
    wait(NULL);
    cout << "PID: " << getpid()<<" PPID: "<< getppid() << "\n";
}