#include <vector>

using namespace std;

bool compBurstProcNum(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

void doProcessSRTF(vector<vector<int>> processVec, int numProcess)
{
    int finProcess = 0;
    int worldTime = 0;
    int procTime = 0;
    vector<vector<int>> arrivedVec;
    vector<int> solving;

    int totalCPU = 0;
    const int numProcessConst = numProcess;
    for (int i = 0; i < numProcess; i++)
    {
        totalCPU += processVec[i][1];
    }

    sort(processVec.begin(), processVec.end(), compArrTime);
    while (!processVec.empty() || !(arrivedVec.empty()) || !(solving.empty()))
    {
        //Arriving Processes
        for (int i = 0; i < numProcess; i++)
        {
            if (processVec[i][0] <= 0)
            {
                arrivedVec.push_back(processVec[i]);
                processVec.erase(processVec.begin() + i);
                numProcess -= 1;
                i -= 1;
            }
            else
            {
                processVec[i][0] = processVec[i][0] - 1;
            }
        }

        //Solve Processes
        sort(arrivedVec.begin(), arrivedVec.end(), compBurstProcNum);

        if (solving.empty())
        {
            solving = arrivedVec[0];
            arrivedVec.erase(arrivedVec.begin());
        }

        if (arrivedVec[0][1] < solving[1])
        {
            cout << worldTime - procTime<< " " << solving[3] << " " << procTime << "\n";
            arrivedVec.push_back(solving);
            solving = arrivedVec[0];
            arrivedVec.erase(arrivedVec.begin());
            procTime = 0;
        }

        if (!solving.empty())
        {
            solving[1] -= 1;
            procTime ++;
            if (solving[1] <= 0)
            {
                solving[1] = 0;
                cout << worldTime - procTime +1 << " " << solving[3] << " " << procTime << "x\n";
                solving.clear();
                procTime = 0;
            }
        }

        worldTime++;
    }

    //Total Stats
    cout << "Total time elapsed: " << worldTime << "ns\n";
    cout << "Total CPU burst time: " << totalCPU << "ns\n";
    cout << "Throughput: " << static_cast<float>(numProcessConst) / static_cast<float>(worldTime);
    cout << " processes/ns" <<"\n";

}