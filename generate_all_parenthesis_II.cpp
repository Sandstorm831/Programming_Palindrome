// Problem Link - https://www.interviewbit.com/problems/generate-all-parentheses-ii/
/* Problem solution Function ----------------------------------------------------+
void recursor(int left, int right, vector<string>& vecy, string& owner)     <----+
{
    if (left == 0 && right == 0)
    {
        vecy.push_back(owner);
        owner.pop_back();
        return;
    } 
    else if(right == 0) 
    {
        owner += ')';
        recursor(left-1, right, vecy, owner);
    }
    else if(left == right)
    {
        owner += '(';
        recursor(left, right-1, vecy, owner);
    }
    else
    {
        owner += '(';
        recursor(left , right-1, vecy, owner);
        owner += ')';
        recursor(left-1, right, vecy, owner);
    }
    owner.pop_back();
}
vector<string> Solution::generateParenthesis(int A) {
    string owner = "";
    vector<string> vecy;
    int left = A, right = A;
    recursor(left, right, vecy, owner);
    return vecy;
}
*/
#include <bits/stdc++.h>
using namespace std;
void recursor(int left, int right, vector<string>& vecy, string& owner)
{
    if (left == 0 && right == 0)
    {
        vecy.push_back(owner);
        owner.pop_back();
        return;
    } 
    else if(right == 0) 
    {
        owner += ')';
        recursor(left-1, right, vecy, owner);
    }
    else if(left == right)
    {
        owner += '(';
        recursor(left, right-1, vecy, owner);
    }
    else
    {
        owner += '(';
        recursor(left , right-1, vecy, owner);
        owner += ')';
        recursor(left-1, right, vecy, owner);
    }
    owner.pop_back();
}
vector<string> generateParenthesis(int A)
{
    string owner = "";
    vector<string> vecy;
    int left = A, right = A;
    recursor(left, right, vecy, owner);
    return vecy;
}
int main(){
    int A = 3;
    vector<string> fuk = generateParenthesis(A);
    for (int i = 0; i < fuk.size(); i++)
    {
        cout<<fuk[i]<<endl;
    }
    
}