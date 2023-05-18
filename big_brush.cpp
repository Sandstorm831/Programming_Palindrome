// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<long long>> v;
// vector<long long> dd;
// set<pair<long long, long long>> sety;
// bool cheker(long long x, long long y)
// {
//     if(v[x][y] == v[x+1][y] && v[x][y]== v[x][y+1] && v[x][y] == v[x+1][y+1]) return 1;
//     return 0;
// }
// bool difcheker(long long x, long long y)
// {
//     set<long long> s;
//     for(long long i=0; i<2; i++)
//     {
//         for(long long j=0; j<2; j++)
//         {
//             s.insert(v[x+i][y+j]);
//         }
//     }
//     if(s.size()<=2) return 1;
//     return 0;
// }
// void zeror(long long x, long long y)
// {
//     v[x][y]=0;
//     v[x][y+1]=0;
//     v[x+1][y]=0;
//     v[x+1][y+1]=0;
// }
// void bs(long long x, long long y, queue<pair<long long, long long>>& q)
// {
//     // cout<<" {} "<<x<<" "<<y<<" {} "<<endl;
//     long long inr = max((long long)0, x-1);
//     long long inc = max((long long)0, y-1);
//     long long finr = min( (long long)(v.size()-2), x+1);
//     long long finc = min( (long long)(v[0].size()-2), y+1);
//     for(long long i = inr; i<=finr; i++)
//     {
//         for(long long j = inc; j<=finc; j++)
//         {
//             if(i == x && j == y) continue;
//             // cout<<i<<" <> "<<j<<endl;
//             if(difcheker(i, j))
//             {
//                 if(!cheker(i,j)) 
//                 {
//                     long long counter=0;
//                     if(v[i][j] != 0) counter++;
//                     if(v[i][j+1] != 0) counter++;
//                     if(v[i+1][j+1] != 0) counter++;
//                     if(v[i+1][j] != 0) counter++;
//                     if(counter>=2) 
//                     {
//                         if(sety.find({i,j}) != sety.end()) continue;
//                         q.push({i,j});
//                         sety.insert({i,j});
//                         if(v[i][j] != 0) dd.push_back(v[i][j]);
//                         else if(v[i][j+1] != 0) dd.push_back(v[i][j+1]);
//                         else if(v[i+1][j+1] != 0) dd.push_back(v[i+1][j+1]);
//                         else if(v[i+1][j] != 0) dd.push_back(v[i+1][j]);
//                         // cout<<i<<"()"<<j<<endl;
//                     }
//                 }   
//             }
//         }
//     }

// }
// int main()
// {
//     dd.clear();
//     long long n,m;
//     cin>>n>>m;
//     v.resize(n, vector<long long>  ());
//     for(long long j=0; j<n; j++)
//     {
//         for(long long k=0;k<m; k++)
//         {
//             long long x;
//             cin>>x;
//             v[j].push_back(x);
//         }
//     }
//     vector<vector<long long>> orig = v;
//     vector<pair<long long, long long>> ans;
//     queue<pair<long long,long long>> q;
//     // cout<<"hehehe";
//     for(long long j=0; j<n-1; j++)
//     {
//         for(long long k=0; k<m-1; k++)
//         {
//             if(cheker(j,k))
//             {
//                 q.push(make_pair(j,k));
//                 dd.push_back(v[j][k]);
//                 sety.insert({j,k});
//             }            
//         }
//     } 
//     // cout<<"hehe";
//     while(!q.empty())
//     {
//         pair<long long, long long> p = q.front();
//         sety.erase(sety.find(p));
//         q.pop();
//         ans.push_back(p);
//         // dd.push_back(orig[p.first][p.second]);
//         zeror(p.first, p.second);
//         bs(p.first, p.second, q);
//     }
//     for(long long j=0; j<n; j++)
//     {
//         for(long long k=0;k<m;k++)
//         {
//             if(v[j][k]!=0)
//             {
//                 cout<<-1<<endl;
//                 return 0;
//             }
//         }
//     }
//     reverse(ans.begin(), ans.end());
//     reverse(dd.begin(), dd.end());
//     cout<<ans.size()<<endl;
//     for(long long j=0; j<ans.size(); j++)
//     {
//         cout<<ans[j].first+1<<" "<<ans[j].second+1<<" "<<dd[j]<<endl;
//     }

// }
////
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) int(x.size())
#define endl '\n'
const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const ll linf = 9e18 + 5;
 
 
int n, m;
const int N = 1e3 + 5;
int arr[N][N];
 
bool came[N][N];
 

void input() {
	cin >> n >> m;
 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
}
 
bool good(int x, int y) {
	if (came[x][y]) {
		return false;
	}
	if (x == 0 || y == 0) {
		return false;
	}
	if (x == n || y == m) {
		return false;
	}
 
	int color = -1;
	for (int i = x; i <= x + 1; i++) {
		for (int j = y; j <= y + 1; j++) {
			if (arr[i][j] == -1) {
				continue;
			}
			if (color == -1) {
				color = arr[i][j];
				continue;
			}
 
			if (arr[i][j] != color) {
				return false;
			}
		}
	}
 
	return true;
}
 
void solve() {
	vector<vector<int>> ans;
	stack<pair<int, int>> fins;
 
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (good(i, j)) {
				came[i][j] = true;
				fins.push(mp(i, j));
			}
		}
	}
 
	
	int have = n * m;
	while (have) {
		if (fins.empty()) {
			cout << -1;
			return;
		}
 
		int x = fins.top().fi, y = fins.top().se;
		fins.pop();
	
		
		int color = -1;
		for (int i = x; i <= x + 1; i++) {
			for (int j = y; j <= y + 1; j++) {
				if (arr[i][j] == -1) {
					continue;
				}
 
				color = arr[i][j];
				arr[i][j] = -1;
				have--;
			}
		}
		if (color != -1) {
			ans.pb({x, y, color});
		}
		
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (good(i, j)) {
					came[i][j] = true;
					fins.push(mp(i, j));
				}
			}
		}
	}
 
 
	cout << sz(ans) << endl;
	for (int i = sz(ans) - 1; i >= 0; i--) {
		cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int number_of_testcases = 1;
	//cin >> number_of_testcases;
	while (number_of_testcases--) {
		input();
		solve();
	}
 
	return 0;
}