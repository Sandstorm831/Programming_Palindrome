#include <bits/stdc++.h>
using namespace std;
int maxpoints(vector<int> A, vector<int> B){
    vector<long double> andy(A.begin(),A.end()), band(B.begin(),B.end());
    unordered_map<long double,long double> mapy;
    if(andy.size()==0)return 0;
    if(andy.size() == 1) return 1;
    long double max=2;
    long double duplicate,vertical;
    long double n = andy.size();
    for (int i = 0; i < n; i++)
    {
        vertical = 0;
        duplicate=1;
        mapy.clear();
        for (int j = i+1; j < n; j++)
        {
            if (andy[i] == andy[j] )
            {
                if(band[i] == band[j]) duplicate++;
                else vertical++;
            }
            else
            {
                long double slope=0;
                if(band[j] != band[i]) slope = (band[j]-band[i])/(andy[j]-andy[i]);
                //cout<<slope<<" ";
                if(mapy.find(slope)!= mapy.end())
                {
                    mapy[slope]++;
                    
                }
                else mapy[slope] = 1;
            }
        }
        auto itr = mapy.begin();
        while(itr != mapy.end())
        {
            int t = itr->second;
            if((t+duplicate)>max) max = t+duplicate;
            itr++;
        }
        if((vertical+duplicate)>max) max = vertical+duplicate;
        
    }
    return max;
}
int main(){
    vector<int> A = {0,1,-1};
    vector<int> B = {0,1,-1};
    cout<<maxpoints(A,B);
}