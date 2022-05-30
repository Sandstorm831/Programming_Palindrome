//Problem Link - https://www.interviewbit.com/problems/2-sum/
#include <bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int> A, int B){
    int miny=INT_MAX, maxy=INT_MAX;
    int n = A.size();
    unordered_map<int,vector<int>> mapy;
    for (int i = 0; i < n; i++)
    {
        mapy[A[i]].push_back(i);
    }
    for (auto itr = mapy.begin(); itr != mapy.end(); itr++)
    {
        int hell = itr->first;
        auto legion= mapy.find(B-hell);
        if(legion !=  mapy.end())
        {
            for (int i = 0; i < (legion->second).size(); i++)
            {
                if(legion->second[i] != itr->second[0])
                {
                    if (itr->second[0] >= legion->second[i])
                    {
                        if(maxy > itr->second[0])
                        {
                            maxy = itr->second[0];
                            miny = legion->second[i];
                        }
                        else if(maxy ==  itr->second[0])
                        {
                            if(miny > legion->second[i])
                            {
                               miny = legion->second[i]; 
                            }
                            
                        }
                        
                    }
                    else
                    {
                        if(maxy > legion->second[i])
                        {
                            maxy = legion->second[i];
                            miny = itr->second[0];
                        }
                        else if(maxy ==  legion->second[i])
                        {
                            if(miny > itr->second[0])
                            {
                               miny = itr->second[0]; 
                            }
                            
                        }
                        
                    }
                    break;
                }
                else
                {
                    continue;
                }
                
            }   
        }
        continue;
    }
    vector<int> fnla;
    if(miny != INT_MAX )
    {   
        fnla.push_back(miny+1);
        fnla.push_back(maxy+1);
    }
    return fnla;
}
int main()
{
    vector<int> A = {1,1,1}; //This has to be assumed;
    int target  =2;
    vector<int> B = twosum(A,target);
    cout<<B[0]<<" "<<B[1];
}