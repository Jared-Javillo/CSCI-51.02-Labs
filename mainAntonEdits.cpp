#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <cstdlib>

using namespace std;


vector<vector<float> > procIntVector(float numProcess);
vector<float> intSplit(char input[100]);
vector<string> splitStr(char input[100]);
bool compArrTime(const vector<float> &a,const vector<float> &b);

void ProcessCheck(string processType, float numProcess, vector<vector<float> > processVec, int x);
void doProcessFCFS(vector<vector<float> > processVec, float numProcess );

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
        vector<vector<float> > processVec; 
        vector<string> inputTest;
        float numProcess = 0;


        //Gets number of Processes and Process Type
        cin.getline(input,100);
        inputTest = splitStr(input);
        numProcess = stof(inputTest[0]);
        processVec = procIntVector(numProcess);

        //Executes Process
        x = i;
        ProcessCheck(inputTest[1], stoi(inputTest[0]),processVec, x);
        
    }
    
}

void ProcessCheck(string processType, float numProcess, vector<vector<float> > processVec, int x){
        if (processType == "FCFS")
        {
        	cout << endl << x << " FCFS" << endl;
            doProcessFCFS(processVec, numProcess);

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
//First Come First Serve
void doProcessFCFS(vector<vector<float> > processVec, float numProcess ){
    int count = 0;
    float output = 0;
    //float wt[100];
    //Process Finish
    sort(processVec.begin(), processVec.end(),compArrTime);

    // wt[0] = 0;
    // for(int i = 1; i < numProcess; i++)
    // {
    // 	wt[i] = 0;
    // 	for(int j = 0; j < i; j++)
    // 	{
    // 		wt[i] += processVec[j][1]; 
    // 	}
    // }
    // 10 80 1    10 1 80x
    // 10 2 1     90 2 2x
    // 11 10 1    92 3 10x

    for (int i = 0; i < numProcess; i++)
    {
        cout << processVec[i][0] <<" "<<processVec[i][3]<<" "<< processVec[i][1]<<"x"<<"\n";
    }

    float tTE = processVec[numProcess-1][0] + processVec[numProcess-1][1];
    //Process Time Elapsed
    cout <<"Total time elapsed: " << tTE <<"ns\n";

    for (int i = 0; i < numProcess; i++)
    {
        output += processVec[i][1];
    }
   
    //Total CPU Burst Time
    cout <<"Total CPU burst time: " << output <<"ns"<< "\n";
    cout <<"CPU Utilization: " << floor((output/tTE)*100) << "%" <<endl;
    cout <<"Throughput: " << numProcess/tTE << " processes/ns";
    cout <<"Waiting Times: " << endl;
}

vector<vector<float> > procIntVector(float numProcess)
{
    vector<vector<float> > processVec;
    vector<float> tempVec;
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

vector<float> intSplit(char input[100])
{
    int count = 0;
    vector<string> inputSplit;
    vector<float> intSplit;
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
        float num = stof(inputSplit.at(i).c_str());
        intSplit.push_back(num);
    }
    return intSplit;
}

bool compArrTime(const vector<float> &a,const vector<float> &b){
    return a[0]<b[0];
}
