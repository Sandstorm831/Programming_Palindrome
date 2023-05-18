#include <bits/stdc++.h>
using namespace std;

int recursive(int x, int y, int s, int *l)
{
    if (*l + s > y)
    {
        return s / 10;
    }
    return recursive(x, y, 10 * s, l);
}

int main()
{
    int x, y, p = 0, l = 0;
    cin >> x >> y;

    while (l != y)
    {
        int s = x;
        if (y - l < x)
        {
            while (l != y)
            {
                ++l;
                ++p;
            }
        }
        else
        {
            s = recursive(x, y, s, &l);
            l += s;
            ++p;
        }
    }
    cout << p;
}