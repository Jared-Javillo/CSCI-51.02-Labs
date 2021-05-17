#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


vector<int> procIntVector(int numProcess);
vector<int> intSplit(char input[100]);
vector<string> splitStr(char input[100]);

void ProcessCheck(string processType, int numProcess, vector<int> testIntVec);
void doProcessFCFS(vector<int> intVector, int numProcess);

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
        vector<int> testIntVec; 
        vector<string> inputTest;
        int numProcess = 0;

        //Gets number of Processes and Process Type
        cin.getline(input,100);
        inputTest = splitStr(input);
        numProcess = stoi(inputTest[0]);
        testIntVec = procIntVector(numProcess);

        //Executes Process
        ProcessCheck(inputTest[1], stoi(inputTest[0]),testIntVec);
        
    }
    
}

void ProcessCheck(string processType, int numProcess, vector<int> testIntVec){
        if (processType == "FCFS")
        {
            doProcessFCFS(testIntVec, numProcess);

        }else if (processType == "SJF")
        {
            cout << "Used Shortest Job First\n";

        }else if (processType == "SRTF")
        {
            cout << "Used Shortest Remaining Time First\n";

        }else if(processType == "P")
        {
            cout << "Used Priority\n";

        }else if(processType == "RR")
        {
            cout << "Used Round Robin\n";
        }else
        {
            cout <<"Error: Input not Valid\n";
        }
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

void doProcessFCFS(vector<int> intVector, int numProcess ){
    int count = 0;
    int output = 0;
    //Process Finish
    for (int i = 0; i < numProcess; i++)
    {
        cout << intVector[count] <<" "<<intVector[count+1]<<" "<< intVector[count+2]<<"x"<<"\n";
        count += 3;
    }
    //Total Time Elapsed
    count -=3;
    output = intVector[count] + intVector[count+1];
    cout << "Total Time Elapsed: " << output << "ns" <<"\n";

    //CPU Burst time
    count = 0;
    output = 0;
    for (int i = 0; i < numProcess; i++)
    {
        output += intVector[count+1];
        count += 3;
    }
    cout << "Total CPU Burst Time: " << output << "ns" <<"\n";
}



vector<int> procIntVector(int numProcess)
{
    vector<int> intVec;
    vector<int> tempVec;
    char input[100];
    
    for (int i = 0; i < numProcess; i++)
    {
        cin.getline(input,100);
        tempVec = intSplit(input);
        intVec.insert(intVec.end(), tempVec.begin(), tempVec.end());
    }

    return intVec;    
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