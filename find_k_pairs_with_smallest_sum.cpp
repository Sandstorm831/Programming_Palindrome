// Question Link - https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
// Solution 

// Both solutions are important
class Compare{
public:
    bool operator()(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b)
    {
        if(a.first.first+a.first.second >= b.first.first+b.first.second) return true;
        return false;
    }
};
struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>,Compare> pq; 
        unordered_set<pair<int,int>, hashFunction> st;
        vector<vector<int>> ans;
        pq.push(make_pair(make_pair(nums1[0],nums2[0]), make_pair(0,0)));
        int n = k;
        vector<int> dx = {1,0,1};
        vector<int> dy = {0,1,1};
        long long vg = (nums1.size())*(nums2.size());
        st.insert(make_pair(0,0));
        while(n-- > 0 && vg-- > 0)
        {
            pair<pair<int,int>,pair<int,int>> p = pq.top();
            pq.pop();
            vector<int> vv;
            vv.push_back(p.first.first);vv.push_back(p.first.second);
            ans.push_back(vv);
            int x = p.second.first;
            int y = p.second.second;
            for(int i=0; i<3; i++)
            {
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(st.find(make_pair(xx,yy)) == st.end() && xx<nums1.size() && yy<nums2.size())
                {
                    pq.push(make_pair(make_pair(nums1[xx], nums2[yy]), make_pair(xx,yy)));
                    st.insert(make_pair(xx,yy));
                }
            }
        }
        return ans;
    }
};
// A concise solution
class Solution {
public:
    typedef tuple<int, int, int> t;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> ans;
        priority_queue<t, vector<t>, greater<t>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums1[i]+nums2[0], i, 0});
        }
        while(k-- && !pq.empty()){
            auto [a,b,c] = pq.top();
            pq.pop();
            ans.push_back({nums1[b], nums2[c]});
            if(c+1 == nums2.size())
                continue;
            pq.push({nums1[b] + nums2[c+1], b, c+1});
        }
        return ans;
    }
};