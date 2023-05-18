#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, sum[6], maxly;
    cin >> a >> b >> c;
    sum[0] = a + b + c;
    sum[1] = a * (b + c);
    sum[2] = a * b + c;
    sum[3] = (a + b) * c;
    sum[4] = a * b * c;
    sum[5] = a + b * c;
    maxly = sum[0];
    for (int i = 0; i < 6; i++)
    {
        if (sum[i] > maxly)
        {
            maxly = sum[i];
        }
    }
    cout << maxly;
}