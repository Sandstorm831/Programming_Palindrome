#include <bits/stdc++.h>
using namespace std;
/**
int main()
{
    int A=8,B=1;
    int n=0;
    int L = A&B;

    while(L==0)
    {
        n=n+1;
        A = A>>1;
        L = A&B;
    }
    cout<<n;
}

int main(){
    vector<int> A = {0,4,9,7};
    sort(A.begin(), A.end());
    long int b = numeric_limits<int>::max();
    long int n = A.size();
    for(int i=0; i<n-1; i++){
        
        int c = A[i]^A[i+1];
        if(c<b){
            b =c;
        }
        else{
            continue;
        }
            
        
    }
    cout<<b;

}
**/
int main()
{
    int a=2,b=5,c=7;
    cout<<(a^b)<<endl;
    cout<<(b^c)<<endl;
    cout<<(a^c)<<endl;
}