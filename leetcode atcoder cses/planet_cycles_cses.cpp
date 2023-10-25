#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;cin>>n;
    vector<int> v(n+1, 0);for(int i=1; i<=n;i++) cin>>v[i];
    vector<int> cyclep(n+1, 0);
    vector<int> finder(n+1, -2);
    for(int i=1; i<=n; i++)
    {
        if(cyclep[i]==0)
        {
            queue<int> q;
            int curr = i;
            int steps=0;
            while(finder[curr] == -2 && cyclep[curr]==0)
            {
                q.push(curr);                
                finder[curr] = steps;
                curr = v[curr];
                steps++;
            }
            q.push(curr);
            if(finder[curr] == -2 && cyclep[curr] != 0) steps+=cyclep[curr];
            int dex = 1;
            while(!q.empty())
            {
                if(q.front() == q.back()) dex = 0;
                cyclep[q.front()] = steps;
                steps-=dex;
                finder[q.front()]=-2;
                q.pop();
            }
        }
        else continue;
    }
    for(int i=1;i <= n; i++) cout<<cyclep[i]<<" ";
    cout<<endl;
    return 0;
}
////
/* 
Don't know why the following solution is not getting accepted
when essentially the time complextiy is same for both cases
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;cin>>n;
    vector<int> v(n+1, 0);for(int i=1; i<=n;i++) cin>>v[i];
    vector<int> cyclep(n+1, 0);
    vector<int> finder(n+1, -2);
    for(int i=1; i<=n; i++)
    {
        if(cyclep[i]==0)
        {
            int curr = i;
            int steps=0;
            int orig=-2;
            int lop=-1;
            while(finder[curr] != -1)
            {
                if(finder[curr] != -2)
                {
                    cyclep[curr] = steps - finder[curr];
                    lop = cyclep[curr];
                    if(orig == -2) orig = finder[curr];
                    finder[curr] = -1;
                    curr = v[curr];
                    steps++;
                    continue;
                }
                finder[curr] = steps;
                curr = v[curr];
                steps++;
            }
            curr = i;
            int d = 0;
            while(finder[curr] != -1)
            {
                cyclep[curr] = orig-d+lop;
                finder[curr] = -1;
                d++;curr = v[curr];
            }
            curr = i;
            while(finder[curr] == -1) 
            {
                finder[curr] =-2;
                curr = v[curr];
            }
        }
    }
    for(int i=1;i <= n; i++) cout<<cyclep[i]<<" ";
}