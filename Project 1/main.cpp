#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <cstdlib>

#include "fcfs.h"
#include "sjf.h"
#include "srtf.h"
#include "p.h"

using namespace std;

//Utils
vector<vector<int>> procIntVector(int numProcess);
vector<int> intSplit(char input[100]);
vector<string> splitStr(char input[100]);

void ProcessCheck(string processType, int numProcess, vector<vector<int>> processVec, int x);

int main()
{
    int numTests = 0;
    int x = 0;
    char input[100];

    //Gets Test
    cin.getline(input,100);
    numTests = atoi(input);

    for (int i = 1; i <= numTests; i++)
    {   
        vector<vector<int>> processVec; 
        vector<string> inputTest;
        int numProcess = 0;

        //Gets number of Processes and Process Type
        cin.getline(input,100);
        inputTest = splitStr(input);
        numProcess = stoi(inputTest[0]);
        processVec = procIntVector(numProcess);

        //Executes Process
        x=i;
        ProcessCheck(inputTest[1], stoi(inputTest[0]),processVec, x);
        
    }
    
}

void ProcessCheck(string processType, int numProcess, vector<vector<int>> processVec, int x){
        if (processType == "FCFS")
        {
            cout << endl << x << " FCFS" << endl;
            doProcessFCFS(processVec, numProcess);

        }else if (processType == "SJF")
        {
            cout << endl << x << " SJF" << endl;
            doProcessSJF(processVec, numProcess);

        }else if (processType == "SRTF")
        {
            cout << endl << x << " SRTF" << endl;
            doProcessSRTF(processVec, numProcess);

        }else if(processType == "P")
        {
            cout << endl << x << " P" << endl;
            doProcessP(processVec, numProcess);

        }else if(processType == "RR")
        {
            cout << "Used Round Robin\n";
        }else
        {
            cout <<"Error: Input not Valid\n";
        }
}

vector<int> intSplit(char input[100])
{
    int count = 0;
    vector<string> inputSplit;
    vector<int> intSplit;
    char* chars_array;

    inputSplit.clear();
    chars_array = strtok(input," ");
    while(chars_array)
    {
        count++;
        inputSplit.push_back(chars_array);
        chars_array = strtok(NULL, " ");
    }

    count = 0;
    for (int i=0; i<= 2; i++)
    {
        int num = atoi(inputSplit.at(i).c_str());
        intSplit.push_back(num);
    }
    return intSplit;
}

vector<vector<int>> procIntVector(int numProcess)
{
    vector<vector<int>> processVec;
    vector<int> tempVec;
    char input[100];
    
    for (int i = 0; i < numProcess; i++)
    {
        cin.getline(input,100);
        tempVec = intSplit(input);
        tempVec.push_back(i+1);
        processVec.push_back(tempVec);
    }
    return processVec;    
}

vector<string> splitStr(char input[100]){
    vector<string> inputSplit;
    char* chars_array;
    int count=0;

    chars_array = strtok(input," ");
        while(chars_array)
        {
            count++;
            inputSplit.push_back(chars_array);
            chars_array = strtok(NULL, " ");
        }
    return inputSplit;
}