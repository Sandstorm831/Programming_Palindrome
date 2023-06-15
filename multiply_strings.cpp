// Question Link - https://www.interviewbit.com/problems/multiply-strings/
// Solution


// for interview bit submission
string mult(string s, int x)
{
    int rem=0;
    string tex="";
    for(int i=s.size()-1; i>=0; i--)
    {
        int l = s[i]-'0';
        l *= x;
        l += rem;
        rem = l/10;
        tex += (l%10)+'0';
    }
    if(rem != 0) tex += rem+'0';
    reverse(tex.begin(), tex.end());
    return tex;
}
void adit(string& summ, string mer)
{
    string tex="";
    int rem = 0;
    int j = summ.size()-1;
    for(int i=mer.size()-1; i>=0; i--)
    {
        int m = summ[j]-'0' + mer[i]-'0'+rem;
        rem = m/10;
        summ[j] = (m%10)+'0';
        j--;
    }
    int i=summ.size()-mer.size()-1;
    while(rem!=0)
    {
        if(i<0)
        {
            // char tx = ;
            summ.insert(0,1,(rem+'0'));
            rem=0;
            continue;
        }
        int m = summ[i]-'0' +rem;
        rem = m/10;
        summ[i] = (m%10)+'0';
        i--;
    }
}
string Solution::multiply(string A, string B) {
    vector<string> v;
    int k=0;
    for(int i=B.size()-1; i>=0; i--)
    {
        int xx = B[i]-'0';
        string tt = mult(A, xx);
        for(int j=0; j<k; j++) tt+='0';
        v.push_back(tt);
        k++;
    }
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    // cout<<endl;
    string summ = v.back();
    // cout<<summ<<endl;
    for(int i=v.size()-2; i>=0; i--)
    {
        adit(summ, v[i]);
        // cout<<summ<<" | "<<v[i]<<endl;
    }
    int index=-1;
    bool n = false;
    for(int i=0; i<summ.size(); i++)
    {
        if(!n && summ[i]=='0')
        {
            index=i;
        }
        if(summ[i] != '0') n=true;
    }
    int nn = summ.size()-1;
    if(index == -1) return summ;
    else return summ.substr(min(index+1, nn));
}

// For understanding

#include <bits/stdc++.h>
using namespace std;
string mult(string s, int x)
{
    int rem=0;
    string tex="";
    for(int i=s.size()-1; i>=0; i--)
    {
        int l = s[i]-'0';
        l *= x;
        l += rem;
        rem = l/10;
        tex += (l%10)+'0';
    }
    if(rem != 0) tex += rem+'0';
    reverse(tex.begin(), tex.end());
    return tex;
}
void adit(string& summ, string mer)
{
    string tex="";
    int rem = 0;
    int j = summ.size()-1;
    for(int i=mer.size()-1; i>=0; i--)
    {
        int m = summ[j]-'0' + mer[i]-'0'+rem;
        rem = m/10;
        summ[j] = (m%10)+'0';
        j--;
    }
    int i=summ.size()-mer.size()-1;
    while(rem!=0)
    {
        if(i<0)
        {
            // char tx = ;
            summ.insert(0,1,(rem+'0'));
            rem=0;
            continue;
        }
        int m = summ[i]-'0' +rem;
        rem = m/10;
        summ[i] = (m%10)+'0';
        i--;
    }
}
// string Solution::multiply(string A, string B) {

// }
int main()
{
    string A = "31243242535342";
    string B = "0";
    vector<string> v;
    int k=0;
    for(int i=B.size()-1; i>=0; i--)
    {
        int xx = B[i]-'0';
        string tt = mult(A, xx);
        for(int j=0; j<k; j++) tt+='0';
        v.push_back(tt);
        k++;
    }
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    string summ = v.back();
    cout<<summ<<endl;
    for(int i=v.size()-2; i>=0; i--)
    {
        adit(summ, v[i]);
        cout<<summ<<" | "<<v[i]<<endl;
    }
    int index=-1;
    bool n = false;
    for(int i=0; i<summ.size(); i++)
    {
        if(!n && summ[i]=='0')index=i;
    }
    int nn = summ.size()-1;
    if(index == -1) cout<<summ;
    else cout<<summ.substr(min(index+1, nn));

}