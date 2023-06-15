#include <bits/stdc++.h>
using namespace std;
// vector<vector<int>> choose;
// void build(int N){
//     choose[0][0]=1;
//     for(int i=1; i<=2*N; i++){
//         choose[i][0]=1;
//         for(int j=1; j<=i; j++){
//             choose[i][j]=choose[i-1][j];
//             choose[i][j] += choose[i-1][j-1];
//         }
//     }
// }
vector<long long> nge(vector<long long>& v, long long sgn)
{
    long long n = v.size();
    stack<pair<long long,long long>> s;
    s.push(make_pair(v[0], 0));
    vector<long long> ng(n);
    for(long long i=1; i<v.size(); i++)
    {
        if(s.top().first<v[i]) 
        {
            while(!s.empty() && s.top().first<v[i]) 
            {
                ng[s.top().second] = i;
                // cout<<v[i]<<" ";
                s.pop();
            }
            s.push(make_pair(v[i],i));
        }
        else s.push(make_pair(v[i],i));
    }
    while(!s.empty()) 
    {
        if(!sgn) ng[s.top().second]=-1;
        else ng[s.top().second]=n;
        s.pop();
    }
    return ng;
}
vector<int> nextGreater(vector<long long>& arr, int n) {
	stack<int> s;	
    vector<int> result(n, n);
	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;	
			s.pop();
		}
		s.push(i);
	}
    return result;
}
vector<int> prevGreater(vector<long long>& arr, int n) {
	stack<int> s;	
    vector<int> result(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;	
			s.pop();
		}
		s.push(i);
	}
    return result;
}
int main(){
    // unordered_map<int,int> dp;
    // dp[1]=0;
    // cout<<(dp.find(2) == dp.end());
    // cout<<dp[2];
    // dp[2]=0;
    // cout<<dp[2];
    // // char s = '1';
    // string sl = "12 ";
    // cout<<int(sl[0])<<" "<<int(sl[1])<<" "<<int(sl[2])<<endl;
    // string abc = "123";
    // int a = abc[2]-48;
    // int b = abc[1]-48;
    // cout<<b*10+a;
    // cout<<int(s);
    // int ch = 49;
    // char chadr = ch;
    // cout<<chadr;
    // sl += 49;
    // cout<<endl<<sl;
    // int reap = sl[2]-48;
    // cout<<endl<<reap;
    // unordered_set<vector<int>> sety;
    // vector<int> a = {1,2,3,4};
    // vector<int> b = {2,3,4,1};
    // vector<int> c = {1,2,3,4};
    // unordered_set<int> sety;
    // sety.erase( )
    // sety.insert(a); sety.insert(b); sety.insert(c);
    // cout<<sety.size();
    // string e = "dfgif";
    // e.pop_back();
    // // cout<<e;
    // vector<pair<int,int>> hel(3);
    // hel.push_back(make_pair<int,int>(1,2));
    // hel.push_back(make_pair<int,int>(3,4));
    // hel.push_back(make_pair<int,int>(5,6));
    // cout<<hel.size();
    // stack<pair<int,int>> heapy;
    // heapy.push({2,3});
    // heapy.push({4,5});
    // cout<<heapy.top().second;
    // unordered_map<int,int> pairy;
    // stack<pair<int,int>> heapy;
    // pairy.insert({2,6});
    // pairy.insert({1,2});
    // heapy.push({2,6});
    // heapy.push({1,2});
    // int tempo = heapy.top().first;
    // cout<<tempo<<endl;
    // cout<<pairy[2]<<endl;
    // pairy.erase(tempo);
    // cout<<pairy[1]<<endl;
    // cout<<pairy[2];
    // // heapy.pop();
    // // heapy.push({key, value});
    // // pairy.insert({key,value});
    // cout<<"jjjjjjjjj"<<pow(2,2);
    // if(false) cout<<"here";
    // list<pair<int,int>> list1 = { {1,2}, {3,4}, {4,5} };
    // list<pair<int,int>> list2 = { {1,6}, {3,9}, {12,3} };
 
    // // merge operation
    // list2.merge(list1);
 
    // cout << "List: ";
 
    // for (auto it = list2.begin(); it != list2.end(); ++it)
    //     cout << it->second << " ";
    // vector<int> a(0);
    // cout<<a.size();
    // choose.resize(5, vector<int> (5,0));
    // build(2);
    // for(int i=0; i<choose.size(); i++)
    // {
    //     for(int j=0; j<choose[i].size(); j++)
    //     {
    //         cout<<choose[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // long long a = pow(2,50);
    // cout<<a;
    // int a = ceil(double(13)/double(7));
    // cout<<a;
    // cout<<LCM(10,20)l
    // cout<<t<<endl;
    // vector<int> v = {1,2,3,4,5};
    // for(int j=0; j<v.size(); j++)
    // {
    //     cout<<v[j]<<" "; 
    // }
    // cout<<v.size()<<endl;
    // v.clear();
    // cout<<v.size()<<" "<<v[0]<<v[1]<<v[2]<<v[3]<<v[6]<<v[7];
    // for(int j=0; j<v.size(); j++)
    // {
    //     cout<<v[j]<<endl;
    // }
    // cout<<((4>3)*(1<<2));
    // vector<int> a;
    // a.push_back(1);
    // a.push_back(2);
    // a.push_back(3);
    // cout<<accumulate(a.begin(), a.end(), sum);
    // long long x=78;
    // long long b  = __builtin_clz(x);
    // cout<<31-b<<endl;
    char x = 'a';
    cout<<x<<++x<<endl;
}       