// Question Link - https://www.interviewbit.com/problems/salutes/
// Solution

long Solution::countSalutes(string A) {
    long long um = 0;
    long long summ = 0;
    for(long long i=0; i<A.size(); i++)
    {
        if(A[i]=='>')um++;
        else
        {
            summ += um;
        }
    }
    return summ;
}