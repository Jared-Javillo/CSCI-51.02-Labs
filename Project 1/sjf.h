#include <vector>

using namespace std;

bool compArrTime(const vector<int> &a,const vector<int> &b)
{
    return a[0] < b[0];
}

bool compArrProcNum(const vector<int> &a,const vector<int> &b)
{
    return a[3] < b[3];
}

void doProcessSJF(vector<vector<int>> processVec, int numProcess )
{
    int output = 0;
    sort(processVec.begin(), processVec.end(),compArrTime);
}