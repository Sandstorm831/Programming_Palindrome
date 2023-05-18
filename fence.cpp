
#include <iostream>
using namespace std;
int main ()
{
    long long n, k, x, ans = 0;
    cin >> n >> k;
    long long ara[n], sum[n];
    for (int i = 0; i < n; i++) {
        cin >> ara[i];
        if (i == 0) sum[0] = ara[0];
        else sum[i] = sum[i-1] + ara[i];
    }

    long long mn = (long long) 1e16;
    for (int i = 0; i < n-k+1; i++) {
        if (i == 0) x = sum[i+k-1];
        else x = sum[i+k-1] - sum[i-1];
        if (x < 0) x *= -1;
        if (x < mn) {
            mn = x;
            ans = (long long) i;
        }
    }
    cout << ans+1 << endl;
    return 0;
}


//******************** below solution time limit exceeded *****************************

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b;
    cin >> a >> b;
    long long int c[a];
    long long int a1, a2, a3, ald;
    if (a==b)
    {
        ald = 1;
    }
    
    for (int i = 0; i < a; i++)
    {
        cin >> c[i];
    }
    for (int j = 0; j < a - b; j++)
    {
        a1=0, a2=0;
        for (int k = 0; k < b; k++)
        {
            //cout<<c[k+j]<<"  ";
            a1 += c[k+j];
            a2 += c[j+k + 1];
            if (j==0)
            {
                a3=a1;
                ald=1;
            }
        }
        //cout<<a1<<" "<<a2<<endl;
        if (a3 > a2)
        {
            ald = j+2;
            a3=a2;
        }
    }
    cout<<ald;

}