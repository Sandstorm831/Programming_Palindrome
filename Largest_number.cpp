// Problem Link - https://www.interviewbit.com/problems/largest-number/
#include <bits/stdc++.h>
using namespace std;
int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);
 
    // then append X at the end of Y
    string YX = Y.append(X);
 
    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}
int  main(){
    vector<int> A = {3,30,34,5,9}; // This has to be assumed
    vector<string> b;
    for(int i=0;i<A.size();i++){
        b.push_back(to_string(A[i]));
    }
    sort(b.begin(),b.end(),myCompare);
    string ans="";
    for(int i=0;i<b.size();i++){
        ans+=b[i];
    }
    int i=0;
    while(ans[i]=='0'){
        i++;
    }
    if(i==ans.length()){
        ans="0";
    }
    cout<<ans;
}