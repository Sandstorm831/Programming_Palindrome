#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n;
        cin>>n;
        int counter=0;
        int x = n/3;
        counter += 5*x;
        int y = n/2;
        counter +=3*(y-x);
        counter += n-y;
        cout<<counter<<endl;

    }
}