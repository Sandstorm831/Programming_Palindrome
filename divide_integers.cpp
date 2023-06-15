// Question Link - https://www.interviewbit.com/problems/divide-integers/
// Solution

int Solution::divide(int A, int B) {
    if( B == 0 ) return INT_MAX; // divide by zero
    if( B == 1 ) return A;
    if( B == -1 ) return ( A == INT_MIN ) ? INT_MAX : -A;
    if( A == B ) return 1;
    if( B == INT_MIN ) return 0;
    int sign=((A<0)^(B<0)) ? -1:1;
    long long a = A;
    long long b = B;
    a = abs(a);
    b = abs(b);
    long long q=0;
    long long d=0;
    for(long long i=31; i>=0; i--)
    {
        if(d + (b<<i) <= a)
        {
            d += b<<i;
            q = q | (1LL<<i);
        }
    }
    return sign*q;
}
// For understanding solution https://www.youtube.com/watch?v=bdxJHWIyyqI