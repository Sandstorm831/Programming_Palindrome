#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,sum1 = 0, sum2 = 0, sum3 = 0;
    cin>>a;
    int matrix[a][3] ;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>matrix[i][j];

        }
        sum1 += matrix[i][0];
        sum2 += matrix[i][1];
        sum3 += matrix[i][2];
        
    }
    if (sum1 == 0 && sum2 == 0 && sum3 ==0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    
}