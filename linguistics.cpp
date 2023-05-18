#include <bits/stdc++.h>  // TLE int this code, recursion + memoization
using namespace std;
int N=2*10e5;
int a,b,ab,ba;
map<string, bool> dp;
bool recursor(string s, int an, int bn, int abn, int ban, int index)
{
    string str = to_string(an)+to_string(bn)+to_string(abn)+to_string(ban);
    if(an > a || bn > b || abn > ab || ban > ba) return false;
    if(dp.find(str) != dp.end()) return dp[str];
    else if(index == s.length())
    {
        if(a == an && b==bn && abn == ab && ban == ba) return dp[str] = 1;
        else return dp[str] = 0;   
    }
    else if(index == s.length()-1)
    {
        char x = s[index];
        if(x == 'A') return dp[str] = recursor(s, an+1, bn, abn, ban, index+1);
        else return dp[str] = recursor(s, an, bn+1, abn, ban, index+1);
    }
    else
    {
        bool ans;
        string d="";
        d += s[index];
        d += s[index+1];
        if(d == "AB")
        {
            bool ans1, ans2;
            ans2 = recursor(s, an, bn, abn+1, ban, index+2);
            ans1 = recursor(s, an+1, bn, abn, ban, index+1);
            ans = ans1||ans2;
        }
        else if(d == "BA")
        {
            bool ans1, ans2;
            ans2 = recursor(s, an, bn, abn, ban+1, index+2);
            ans1 = recursor(s, an, bn+1, abn, ban, index+1);
            ans = ans1||ans2;
        }
        else
        {
            if(s[index] == 'A') ans = recursor(s, an+1, bn, abn, ban, index+1);
            else ans = recursor(s, an, bn+1, abn, ban, index+1);
        }
        return dp[str] = ans;
    }
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        cin>>a>>b>>ab>>ba;
        string s;
        cin>>s;
        int na=0, nb=0;
        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == 'A') na++;
            else nb++;
        }
        if(na != a+ab+ba || nb != b+ab+ba) 
        {
            cout<<"No"<<endl;
            continue;
        }
        dp.clear();
        bool ans = recursor(s,0,0,0,0,0);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"NO"<<endl;
    }
}
//////////////////
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b,c,d;
    string s;
    cin>>a>>b>>c>>d>>s;
    int n = s.size();
    if(count(s.begin(), s.end(), 'A') != a+c+d || count(s.begin(), s.end(), 'B') != b+c+d){ cout<<"NO"<<endl; return;}
    vector<int> C,D,S;
    for(int i=0; i<n-1; i++)
    {
        if(s[i]!=s[i+1])
        {
            int j=i; 
            while(s[j] != s[j+1] && j<n-1) j++;
            if(s[i] == s[j]) S.push_back((j-i)/2);
            else if(s[i] == 'A' && s[j] == 'B') C.push_back((j-i+1)/2);
            else if(s[i] == 'B' && s[j] == 'A') D.push_back((j-i+1)/2);
            i=j;
        }
    }
    sort(C.begin(), C.end());
    for(int cc: C) if(cc<=c) c-=cc; else S.push_back(cc-1);
    sort(D.begin(), D.end());
    for(int dd: D) if(dd<=d) d-=dd; else S.push_back(dd-1);
    if(c+d<=accumulate(S.begin(), S.end(), 0))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
 
int main(){
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int T; cin >> T; while(T --) solve();
   return 0;
}