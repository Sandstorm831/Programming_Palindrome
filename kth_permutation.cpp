// Question Link - https://www.interviewbit.com/problems/k-th-permutation/
// Solution

long long factorial(long long x)
{
    if(x==0 || x==1) return 1;
    else return x*factorial(x-1);
}
vector<int> Solution::findPerm(int A, long B) {
    B = (long long)B; 
    int count=1;
    while(factorial(count) <= B) count++;
    int rem = A-count;
    vector<int> V;
    set<int> s;
    for(int i=0; i<A; i++)
    {
        if(i<rem) V.push_back(i+1);
        else s.insert(i+1);
    }
    for(int j=rem; j<A; j++)
    {
        int det=0;
        for(int k=0; k<count; k++)
        {
            if(B>=k*factorial(count-1) + 1 && B <= (k+1)*factorial(count-1))
            {
                det=k;
                break;
            }
        }
        set<int>::iterator it = s.begin();
        advance(it,det);
        V.push_back(*it);
        s.erase(it);
        B -= (det*factorial(count-1));
        count--;
    }
    return V;
}
