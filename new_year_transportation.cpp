#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, s = 1;
    cin >> m >> n;
    int a[m - 1];
    for (int i = 0; i < m - 1; i++)
    {
        cin >> a[i];
    }
    while (s < n)
    {
        s += a[s-1];
    }
    if (s == n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}