// Question Link - https://www.interviewbit.com/problems/deserialize/
// Solution

vector<string> Solution::deserialize(string A) {
    vector<string> vrg;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] - '0' >= 0 && A[i] - '0' <=9) continue;
        else if(A[i] == '~') continue;
        string t="";
        int j;
        for(j=i; j<A.size(); j++)
        {   
            if(A[j] - '0' >= 0 && A[j] - '0' <=9) break;
            if(A[j] - 'A' >= 0 && A[j] - 'A' <= 25) t+=A[j]+32;
            else if(A[j] - 'a' >= 0 && A[j] - 'a' <= 25) t+=A[j];
        }
        i=j;
        vrg.push_back(t);
    }
    return vrg;
}
