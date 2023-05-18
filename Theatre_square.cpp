#include<iostream>
#include<string>
using namespace std;
int main(){
    long long int m,n,a,s,r;
    cin>>n>>m>>a;
    cout<<endl;
    if (n%a == 0)
    {
        s = n/a;
    }
    else if (n%a != 0)
    {
        s = int(n/a) + 1;
    }

    if (m%a ==0)
    {
        r = m/a;
    }
    else if (m%a!=0)
    {
        r=int(m/a) +1;
    }
    //string fie = to_string(s*r);
    cout<< s*r;
    
}