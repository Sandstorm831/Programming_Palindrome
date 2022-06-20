// Problem Link - https://www.interviewbit.com/problems/simplify-directory-path/
/*Problem Solution Function ------------------------+
string Solution::simplifyPath(string A) {       <---+
    vector<string> collector;
    string maker = "";
    A.push_back('/');
    for (int i = 0; i < A.size(); ++i)
    {
        if(A[i] == '/')
        {
            if(maker.empty())continue;
            else if(maker == "."){}
            else if(maker == "..")
            {
                if(!collector.empty()) collector.pop_back();
            }
            else collector.push_back(maker);
            maker.clear();
        }
        else maker.push_back(A[i]);
    }
    if(collector.empty()) return "/";
    A.clear();
    for (int i = 0; i < collector.size(); ++i)
    {
        A.append("/"+collector[i]);
    }
    return A;
}
*/
#include<bits/stdc++.h>
using namespace std;
string simplifyPath(string A)
{
    vector<string> collector;
    string maker = "";
    A.push_back('/');
    for (int i = 0; i < A.size(); ++i)
    {
        if(A[i] == '/')
        {
            if(maker.empty())continue;
            else if(maker == "."){}
            else if(maker == "..")
            {
                if(!collector.empty()) collector.pop_back();
            }
            else collector.push_back(maker);
            maker.clear();
        }
        else maker.push_back(A[i]);
    }
    if(collector.empty()) return "/";
    A.clear();
    for (int i = 0; i < collector.size(); ++i)
    {
        A.append("/"+collector[i]);
    }
    return A;
}
int main()
{
    string A = "/a/./b/../../c/";
    cout<<simplifyPath(A);

}