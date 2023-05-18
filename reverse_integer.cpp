// Question Link - https://www.interviewbit.com/problems/reverse-integer/
// Reverse Integer

 int Solution::reverse(int A) {
    long long  h = INT_MAX;
    long long l = INT_MIN;
    int sin = 0;
    if(A<0) 
    {
        sin=-1;
        A = -A;
    }
    else if(A==0) return 0;
    else sin=1;
    long long s = 0;
    while(A>0)
    {
        int x = A%10;
        s = s*10+x;
        A = A/10;
    }
    s = sin*s;
    if(s>h || s<l) return 0;
    else return s;
}