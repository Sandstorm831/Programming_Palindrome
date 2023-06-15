// Question Link - https://www.interviewbit.com/problems/palindromic-binary-representation/
// Solution

#include <bits/stdc++.h>
using namespace std;
int constr(int group_count, int aux, int delma)
{
    vector<int> num(32,0);
    int i=0;
    int dig;
    if(delma==2)
    {
        dig = 2*group_count;
        num[0] = num[dig-1] = 1;
        while(aux)
        {
            num[group_count+i] = num[group_count-1-i] = aux&1;
            aux = aux>>1;
            i++;
        }
    }
    else if(delma==1)
    {
        dig = 2*group_count+1;
        num[0] = num[dig-1] = 1;
        num[group_count] = 1;
        while(aux)
        {
            num[group_count+1+i] = num[group_count-1-i] = aux&1;
            aux = aux>>1;
            i++;
        }
    }
    else if(delma==0)
    {
        dig = 2*group_count+1;
        num[0] = num[dig-1] = 1;
        num[group_count] = 0;
        while(aux)
        {
            // cout<<endl<<group_count+i+1<<"|"<<endl;
            num[group_count+1+i] = aux&1;
            num[group_count-1-i] = aux&1;
            aux = aux>>1;
            i++;
        }
    }
    int finum=0;
    for(int i=0; i<dig;i++)
    {
        finum+= (1<<i)*num[i];
    }
    return finum;
}
int nthpalindrom(int A)
{
    int countbefore=1;
    int groupno = 0;
    int group_count = 0;
    int temp_count=0;
    while(countbefore<A)
    {
        groupno++;
        temp_count =countbefore;
        countbefore += 3*(1<<(groupno-1));
        group_count++;
    }
    int offset = A - temp_count-1;
    int delma;
    int aux;
    if(offset+1 <= 1<<(group_count-1))
    {
        delma = 2;
        aux = offset;
    }
    else
    {
        if((offset+1-(1<<(group_count-1)))%2) delma=0;
        else delma = 1;
        aux = (offset-(1<<(group_count-1)))/2;
    }
    cout<<group_count<<"|"<<aux<<"|"<<delma<<"|"<<offset<<endl;
    // return 0;
    return constr(group_count, aux, delma);
}
int main()
{
    int A;
    cin>>A;
    if(A==1) cout<<1<<endl;
    else cout<<nthpalindrom(A)<<endl;
}