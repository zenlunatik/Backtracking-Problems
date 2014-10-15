#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> solution;

void
processSolution(int solnSize)
{
    for (int ii = 0; ii < solnSize; ii++) {
        cout<<char(solution[ii] + 'a' - 1)<<" ";
    }
    cout<<endl;
}

void
findCandidates(int charsLeft, string& str, vector<int>& candidates)
{
    int start = str.length() - charsLeft;
    if (charsLeft >= 2) {
        if (str[start] == '1' && str[start+1] == '0') {
            candidates.push_back(10);
            return;
        }
    }
    int val = atoi(str.substr(start,1).c_str());
    candidates.push_back(val);
    if (--charsLeft) {
        val = atoi(str.substr(start,2).c_str());
        if (val <= 26 && val > 0) {
            candidates.push_back(val);
        }
    }
}

void
findSolutions(int index, int charsLeft, string& str, int solnSize)
{
    if (charsLeft == 0) {
        processSolution(solnSize);
        return;
    }

    vector<int> candidates;
    findCandidates(charsLeft, str, candidates);
    for (int ii = 0; ii < candidates.size(); ii++) {
        solution[index] = candidates[ii];
        if (candidates[ii] < 10) {
            findSolutions(index+1, charsLeft-1, str, solnSize+1);
        } else {
            findSolutions(index+1, charsLeft-2, str, solnSize+1);
        }
    }

}


int main()
{
    string str = "12258";
    solution.resize(str.length());
    findSolutions(0, str.length(), str, 0);
}


