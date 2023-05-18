#include <bits/stdc++.h>
using namespace std;
int mostFrequent(vector<int> arr, int n)
{
    map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
  
    int max_count = 0, res = -1;
    for (auto i : hash) {
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }
    int counter=0;
    for(int j=0; j<n; j++)
    {
        if(arr[j] == res) counter++;
    }
    return counter;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int j=0; j<n; j++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int maxy = mostFrequent(v, n);
    int rep = n - maxy;
    int ans = rep;
    while(rep>0)
    {
        rep -= maxy;
        maxy *=2;
        ans++;
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}