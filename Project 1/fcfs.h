#include <vector>

using namespace std;

bool compArrTime(const vector<int> &a,const vector<int> &b){
    return a[0] < b[0];
}

bool compArrProcNum(const vector<int> &a,const vector<int> &b){
    return a[3] < b[3];
}

void doProcessFCFS(vector<vector<int>> processVec, int numProcess ){
    int count = 0;
    int output = 0;
    int timePassed = 0;
    //Process Finish
    sort(processVec.begin(), processVec.end(),compArrTime);
    for (int i = 0; i < numProcess; i++)
    {
        if(timePassed < processVec[i][0]  )
        {
            timePassed += (processVec[i][0] - timePassed) + processVec[i][1];
        }else if(timePassed >= processVec[i][0])
        {
            timePassed +=  processVec[i][1];
        }
        cout << timePassed << "\n";
        cout << processVec[i][0] <<" "<<processVec[i][3]<<" "<< processVec[i][1]<<"x"<<"\n";
    }

    //Output Time
    cout <<"Total time elapsed: " << timePassed <<"ns\n";

    for (int i = 0; i < numProcess; i++)
    {
        output += processVec[i][1];
    }

    //Output Overalls
    cout <<"Total CPU burst time: " << output <<"ns"<< "\n"; 
    output = ( static_cast<float>(output) / static_cast<float>(timePassed) ) *100;
    cout <<"CPU Utilization: "<< output << "%\n";
    cout << "Throughput: " << static_cast<float>(numProcess) / static_cast<float>(timePassed);
    cout << " processes/ns" <<"\n";

    //Output Waiting times per Process
    cout << "Waiting Times: \n";
    for (int i = 0; i < numProcess; i++)
    {
        cout << "Process " << i+1 << " " << "0ns\n";
    }cout << "Average waiting time: 0ns \n";

    sort(processVec.begin(), processVec.end(),compArrProcNum);

    //Output Turnaround times per Process
    cout << "Turnaround Times: \n";
    output = 0;
    for (int i = 0; i < numProcess; i++)
    {
        cout << "Process " << i + 1 << " " << processVec[i][1] << "ns\n";
        output += processVec[i][1];
    }cout << "Average Turnaround time: " << output/numProcess <<"ns\n";
    
    //Output Response times per Process
    cout << "Response Times: \n";
    for (int i = 0; i < numProcess; i++)
    {
        cout << "Process " << i+1 << " " << "0ns\n";
    }cout << "Average response time: 0ns \n";
}

