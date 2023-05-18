// Question Link - https://www.interviewbit.com/problems/hotel-bookings-possible/
// Solution

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int>> v;
    for(int i=0; i<arrive.size(); i++)
    {
        v.push_back(make_pair(arrive[i],0));
        v.push_back(make_pair(depart[i],1));
    }
    sort(v.begin(), v.end());
    int maxy=INT_MIN;
    int curr=0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].second == 0) curr++;
        else curr--;
        maxy= max(maxy, curr);
    }
    return maxy<=K;
}