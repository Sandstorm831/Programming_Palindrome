// Question LInk - https://www.interviewbit.com/problems/frequency-of-characters/
// solution 

vector<int> Solution::solve(string A) {
    vector<int> v(26,0);
    for(int i=0;i<A.size(); i++)
    {
        v[A[i]-'a']++;
    }
    return v;
}
