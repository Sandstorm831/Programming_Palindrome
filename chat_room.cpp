#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int it = 0;
    getline(cin, a);
    int l = a.length();
    for (int i = 0; i < l; i++)
    {
        if (it == 0)
        {
            if (a[i] == 'h')
            {
                it = 1;
            }
            else
            {
                it = 0;
            }
        }
        else if (it == 1)
        {
            if (a[i] == 'e')
            {
                it = 2;
            }
            else
            {
                it == 1;
            }
        }
        else if (it == 2 || it == 3)
        {
            if (a[i] == 'l')
            {
                it += 1;
            }
            else
            {
                it = it;
            }
        }
        else if (it == 4)
        {
            if (a[i] == 'o')
            {
                it = 5;
            }
            else
            {
                it = it;
            }
        }
        else
        {
        }
    }
    if (it == 5)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}