// Question Link - https://www.interviewbit.com/problems/distribute-candy/
// Solution 

int Solution::candy(vector<int> &A) {
    vector<int> cn(A.size(), 1);
    for(int i=1; i<A.size(); i++)
    {
        if(A[i]>A[i-1]) cn[i]=cn[i-1]+1;
    }
    for(int i=A.size()-2; i>=0;i--)
    {
        if(A[i]>A[i+1])cn[i] = max(cn[i+1]+1, cn[i]);
    }
    int summ=0;
    for(int i=0; i<cn.size();i++) summ += cn[i];
    return summ;    
}
