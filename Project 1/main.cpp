#include <string>
#include <iostream>

using namespace std;

void ProcessCheck(char input[100]);

int main()
{
    int numTests = 0;
    int numProcess = 0;
    int x = 0;
    char input[100];

    cin.getline(input,100);
    numTests = atoi(input);

    for (int i = 1; i <= numTests; i++)
    {           
        cout << "Test Case: "<< i << "\n";
        cin.getline(input,100);
        ProcessCheck(input);
        cin.getline(input,100);
        numProcess = atoi(input);
        for (int i = 0; i < numProcess; i++)
        {
            cout << "Process " << i+1 <<" done\n";
        }
    }
    
}

void ProcessCheck(char input[100])
{       string s(input);
        if (s == "FCFS")
        {
            cout << "Used First Come First Served\n";

        }else if (s == "SJF")
        {
            cout << "Used Shortest Job First\n";

        }else if (s == "SRTF")
        {
            cout << "Used Shortest Remaining Time First\n";

        }else if(s == "P")
        {
            cout << "Used Priority\n";

        }else if(s == "RR")
        {
            cout << "Used Round Robin\n";
        }else
        {
            cout <<"Error: Input not Valid\n";
        }
}