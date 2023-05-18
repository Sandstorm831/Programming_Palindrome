// Question Link - https://www.interviewbit.com/problems/largest-coprime-divisor/
// Solution

int gcd(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b) return gcd(a - b, b);
    return gcd(a, b - a);
}
int Solution::cpFact(int A, int B) {
    while(gcd(A, B) != 1)
    {
        A /= gcd(A,B);
    }
    return A;
}
