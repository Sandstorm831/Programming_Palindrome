#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0, b = 0, c = 0, d = 0, e, f;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int l;
        cin >> l;
        if (l == 1)
        {
            a += 1;
        }
        else if (l == 2)
        {
            b += 1;
        }
        else if (l == 3)
        {
            c += 1;
        }
        else
        {
            d += 1;
        }
    }
    if (c >= a)
    {
        cout << d + (b + 1) / 2 + c;
    }
    else
    {
        if ((a - c + 2 * b) % 4 == 0)
        {
            cout << d + c + (a - c + 2 * b) / 4;
        }
        else
        {
            cout << d + c + (a - c + 2 * b) / 4 + 1;
        }
    }
}