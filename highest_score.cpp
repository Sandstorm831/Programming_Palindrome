// Question Link - https://www.interviewbit.com/problems/highest-score/
// Solution 

int Solution::highestScore(vector<vector<string> > &A) {
    unordered_map<string, int> tot;
    unordered_map<string, int> no;
    for(int i=0; i<A.size(); i++)
    {
        if(!tot[A[i][0]]) tot[A[i][0]] = stoi(A[i][1]);
        else tot[A[i][0]] += stoi(A[i][1]);
        no[A[i][0]]++;
    }
    int maxy = INT_MIN;
    for(auto it = no.begin(); it!=no.end(); it++)
    {
        maxy = max(maxy, (tot.find(it->first)->second) / it->second);
    }
    return maxy;
}
