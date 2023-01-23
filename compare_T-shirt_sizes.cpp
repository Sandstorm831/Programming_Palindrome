#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        string first, second;
        cin>>first>>second;
        if(first.back() == second.back() && first.size()==second.size()) cout<<'='<<endl;
        else if(first.back()=='S' && (second.back()=='M' || second.back() == 'L' || second.size()<first.size())) cout<<'<'<<endl;
        else if(first.back()=='S' && second.back() == 'S' && second.size()>first.size()) cout<<'>'<<endl;
        else if(first.back() == 'M'&& second.back()=='S') cout<<'>'<<endl;
        else if(first.back() == 'M' && second.back() =='L') cout<<'<'<<endl;
        else if(first.back() == 'L' && (second.back() == 'S' || second.back() == 'M' || first.size()>second.size())) cout<<'>'<<endl;
        else if(first.back() == 'L' && second.back() == 'L' && first.size()<second.size()) cout<<'<'<<endl;
    }
}