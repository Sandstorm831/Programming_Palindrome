// Question Link - https://www.interviewbit.com/problems/subarrays-with-distinct-integers/
// Solution

int Solution::solve(vector<int> &A, int B) {
    int count=0;
    unordered_map<int,int> ss;
    int j=0; 
    for(int i=0; i<A.size(); i++)
    {
        if(ss.find(A[i]) == ss.end()) ss[A[i]] = 1;
        else ss[A[i]]++;
        while(ss.size() > B)
        {
            if(ss[A[j]] == 1) ss.erase(A[j]);
            else ss[A[j]]--;
            j++;
        }
        // cout<<j<<" "<<i<<endl;
        count += i-j+1;
    }
    ss.clear();
    j=0;
    int ncount=0;
    for(int i=0; i<A.size(); i++)
    {
        if(ss.find(A[i]) == ss.end()) ss[A[i]] = 1;
        else ss[A[i]]++;
        while(ss.size() > B-1)
        {
            if(ss[A[j]] == 1) ss.erase(A[j]);
            else ss[A[j]]--;
            j++;
        }
        // cout<<j<<" "<<i<<endl;
        ncount += i-j+1;
    }
    // cout<<count<<" | "<<ncount<<endl;
    return count-ncount;
}
