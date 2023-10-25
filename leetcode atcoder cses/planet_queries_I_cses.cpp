#include <bits/stdc++.h>
using namespace std;

/* This solution Gives TLE, as the cycle size increases
int main()
{
    int n,q;cin>>n>>q;
    vector<int> v(n+1, 0); 
    for(int i=1; i<= n; i++) cin>>v[i];
    vector<int> cyclep(n+1, -1);
    while(q--)
    {
        int a, b;cin>>a>>b;
        unordered_map<int,int> ump;
        int curr = a;
        int step = 0;
        while(ump.find(curr) == ump.end() && step < b && cyclep[curr] == -1)
        {
            ump[curr] = step;
            step++;
            curr = v[curr];
        }
        if(step == b) cout<<curr<<endl;
        else if(ump.find(curr) != ump.end())
        {
            cout<<"here"<<endl;
            int ini = ump[curr];
            int cycle = step-ini;
            b -= ini;
            b%=cycle;
            step =0;
            ini  = curr;
            while(step != b)
            {
                step++;
                curr = v[curr];
            }
            cout<<curr<<endl;
            cyclep[ini] = cycle;
            curr = v[ini];
            while(curr != ini)
            {
                cyclep[curr] = cycle;
                curr = v[curr];
            }
        }
        else if(cyclep[curr] != -1)
        {
            cout<<"dad"<<endl;
            b -= step;
            b%=cyclep[curr];
            step=0;
            while(step != b)
            {
                step++;
                curr = v[curr];
            }
            cout<<curr<<endl;
        }
    }
}
*/
// Solution appraoch, binary lifting & This approach also gives TLE if 
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
// are not used
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,q;cin>>n>>q;
    vector<vector<int>> parent(30, vector<int> (n+1));
    for(int i=1; i<= n; i++) 
    {
        cin>>parent[0][i];
    }
    for(int i=1; i<30; i++)
    {
        for(int j=1; j<=n; j++)
        {
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
    while(q--)
    {
        int a,b;cin>>a>>b;
        for(int i=29; i>=0; i--)
        {
            if(b & (1<<i)) a = parent[i][a];
        }
        cout<<a<<endl;
    }
}