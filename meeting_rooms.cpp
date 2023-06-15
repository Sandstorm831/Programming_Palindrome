// Question LInk - https://www.interviewbit.com/problems/meeting-rooms/
// solution 

bool func(pair<int,int> a, pair<int,int> b)
{
    if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    else if(a.first == b.first && a.second < b.second) return true;
    else if(a.first == b.first && a.second > b.second) return false;
    else if(a.first == b.first && a.second == b.second) return true;
}
int Solution::solve(vector<vector<int> > &A) {
    vector<pair<int,int>> v;
    for(int i=0; i<A.size(); i++)
    {
        v.push_back(make_pair(A[i][0],1));
        v.push_back(make_pair(A[i][1],0));
    }
    sort(v.begin(), v.end(), func);
    int maxx = INT_MIN;
    int curr=0;
    for(int i=0;i<v.size(); i++)
    {
        if(v[i].second == 1) 
        {
            curr++;
            maxx = max(maxx, curr);
        }
        else
        {
            curr--;
        }
    }
    return maxx;
}