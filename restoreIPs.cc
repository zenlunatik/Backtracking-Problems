#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;


vector<int> g_solution;


void
processSolution()
{
    for (int ii = 0; ii <= 2; ii++) {
        cout<<g_solution[ii]<<".";
    }
    cout<<g_solution[3]<<endl;
}

void
findCandidates(vector<int>& candidates, vector<int>& indexes, string& str, int k, int current)
{
    int rem = str.length() - current;
    int count = 1;
    int remSlots = 4 - k - 1;
    int min = remSlots;
    int max = remSlots * 3;
    while (rem >= 0) {
        if (count == 4) {
            return;
        }
        string sub = str.substr(current, count);
        --rem;
        if (rem < min || rem > max) {
            ++count;
            continue;
        }
        int num = atoi(sub.c_str());
        if (num < 0 || num > 255){
            ++count;
            continue;
        }

        candidates.push_back(num);
        indexes.push_back(count);
        ++count;
    }

}

void
restoreIPs(string& str, int k, int n, int current)
{
    if (k == n) {
        processSolution();
        return;
    }
    vector<int> candidates;
    vector<int> indexes;
    findCandidates(candidates, indexes, str, k, current); 
    for (int ii = 0; ii < candidates.size(); ii++) {
        g_solution[k] = candidates[ii];
        restoreIPs(str, k+1, 4, current+indexes[ii]);
    }
}

int
main()
{
    g_solution.resize(4);
    //string str = "25525511135";
    //string str = "2552551113";
    string str = "252551113";
    int k = 0;
    int n = 4;
    int current = 0;
    if (str.length() < 4 || str.length() > 12) {
        exit(1);
    }
    restoreIPs(str, 0, 4, 0);
}

