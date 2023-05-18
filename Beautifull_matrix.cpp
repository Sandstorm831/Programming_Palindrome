#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5][5], b[2];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>a[i][j];
            if (a[i][j] == 1)
            {
                b[1] = i;
                b[2] = j;
            }
            
        }
        
    }
    cout<<abs(2-b[1]) + abs(2 - b[2]);
    
}