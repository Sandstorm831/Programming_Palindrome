// Question Link - https://www.interviewbit.com/problems/painters-partition-problem/
// Solution 

bool feasible(long long a, long long b, vector<long long> C, long long d)
{
    long long int summ=0;
    long long int counter=0;
    for(long long i=0; i<C.size();i++)
    {
        if(C[i]*b > d) return false;
        summ += C[i]*b;
        if(summ > d)
        {
            counter++;
            summ = C[i]*b;
        }
    }
    if(summ<=d && summ>0) counter++;
    return counter<=a;
}
int Solution::paint(int A, int B, vector<int> &C) {
    vector<long long> c(begin(C), end(C));
    long long a = A;
    long long b = B;
    long long ini = 0;
    long long fin = 1e18;
    long long mod = 10000003; 
    long long mid=10;
    while(ini <= fin)
    {
        mid = (ini+fin)/2;
        if(feasible(a, b, c, mid)) fin = mid-1;
        else ini = mid+1;
    }
    if(feasible(a,b,c,mid)) return int(mid%mod);
    return int((mid+1)%mod);
}
