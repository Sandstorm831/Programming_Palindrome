// // Can't figure out the problem, but .........
// // it is bases on following idea - abcded  ----> [(abcdecba)(abcdecba)][abce]  Where d will be the first repeating element
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     long long cases;
//     cin>>cases;
//     for(long long i=0; i<cases; i++)
//     {
//         long long n;
//         cin>>n;
//         vector<long long> s;
//         vector<long long> sizes;
//         vector<pair<long long,long long>> insertions;
//         for(long long j=0; j<n; j++)
//         {
//             long long x;
//             cin>>x;
//             s.push_back(x);
//         }
//         unordered_map<char,pair<long long,long long>> ump;
//         for(long long j=0; j<s.size(); j++)
//         {
//             if(ump.find(s[j]) == ump.end()) ump[s[j]]={1,j};
//             else ump[s[j]].first++;
//         }
//         bool oly=true;
//         for(auto itr=ump.begin(); itr!=ump.end(); itr++)
//         {
//             if((itr->second.first)%2 != 0) 
//             {
//                 cout<<-1<<endl;
//                 oly=false;
//                 break;
//             }
//         }
//         ump.clear();
//         if(!oly) continue;
//         vector<long long> newstr;
//         long long oldl=0;
//         while(!s.empty())
//         {
//             for(long long j=0; j<s.size(); j++)
//             {
//                 long long a = s[j];
//                 if(ump.find(a) == ump.end())
//                 {
//                     ump[a] = {1,j};
//                 }
//                 else
//                 {
//                     long long index = ump.find(a)->second.second;
//                     for(long long k=0; k<index; k++) newstr.push_back(s[k]);
//                     for(long long k=j-1; k>index; k--) newstr.push_back(s[k]);
//                     if(2*j+2*index != 0)sizes.push_back(2*j + 2*index);
//                     else sizes.push_back(s.size());
//                     for(long long k=index+1; k<j; k++) insertions.push_back({oldl+j+k-index, s[k]});
//                     for(long long k=index-1; k>=0; k--) insertions.push_back({oldl+j+index-k+j-index-1, s[k]});
//                     for(long long k=index-1; k>=0; k--) insertions.push_back({oldl+j+index-k-1, s[k]});
//                     if(j != s.size()-1)  for(long long m = j+1; m<s.size(); m++) newstr.push_back(s[m]);
//                     ump.clear();
//                     break;
//                 }
//             }
//             s = newstr;
//             oldl = sizes.back();
//             newstr.clear();
//         }
//         cout<<insertions.size()<<endl;
//         for(long long j=0; j<insertions.size(); j++)
//         {
//             cout<<insertions[j].first<<" "<<insertions[j].second<<endl;
//         }
//         cout<<sizes.size()<<endl;
//         for(long long j=0; j<sizes.size(); j++) cout<<sizes[j]<<" ";
//         cout<<endl;
//     }
// }
/////////
#include <bits/stdc++.h>
using namespace std;
void reverse_pref(vector<int> &ar, vector<pair<int, int>> &ans, vector<int> &lens, int &mdf, int len)
{
    for (int i = 0; i < len; ++i) ans.emplace_back(len + mdf + i, ar[i]);
    if (len != 0) lens.push_back(len * 2);
    mdf += len * 2;
    reverse(ar.begin(), ar.begin() + len);
}
void move_to_front(vector<int> &ar, vector<pair<int, int>> &ans,vector<int> &lens, int &mdf, int id)
{
    reverse_pref(ar, ans, lens, mdf, id);
    reverse_pref(ar, ans, lens, mdf, id + 1);
}
 
int IlkrasTEQ1Solve(int n, vector<int> ar) {
 
    int xr = 0;
    unordered_map<int, int> cnt;
    for (auto &it : ar) {
        cnt[it]++;
    }
    for (auto &it : cnt)
        if (it.second % 2) {
            cout << "-1\n";
            return 0;
        }
    vector<int> br = ar;
    sort(br.rbegin(), br.rend());
    vector<pair<int, int>> ans;
    vector<int> lens;
    ans.reserve(n * n * 2);
    lens.reserve(n * 2);
    int mdf = 0;
    for (int i = 0; i < n; ++i) {
        int fnd = (int)(find(ar.begin() + i, ar.end(), br[i]) - ar.begin());
        move_to_front(ar, ans, lens, mdf, fnd);
    }
    for (int i = 0; i < n; ++i) {
        int lst = i;
        for (; lst < n && ar[lst] == ar[i]; ++lst) {
        }
        // cout<<lst-i<<endl;
        lens.push_back(lst - i);
        i = lst - 1;
    }
    cout << (int)ans.size() << "\n";
    for (auto &it : ans) cout << it.first << " " << it.second << "\n";
    cout << (int)lens.size() << "\n";
    for (auto &it : lens) cout << it << " ";
    cout << "\n";
    return 0;
}
 
int main() {
    (*cin.tie(0)).sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (auto &it : ar) cin >> it;
        IlkrasTEQ1Solve(n, ar);
    }
    return 0;
}