// Question Link - https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150
// solution

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> pp;
        for(int i=0; i<profits.size(); i++)
        {
            pp.push_back(make_pair(capital[i], profits[i]));
        }
        sort(pp.begin(), pp.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        int j=0;
        for(int i=0; i<k; i++)
        {
            while(j<pp.size() && pp[j].first <= w) {pq.push(-pp[j].second);j++;}
            if(!pq.empty()) {w-=pq.top();pq.pop();}
        }
        return w;
    }
};
// For explanation https://leetcode.com/problems/ipo/solutions/98216/python-priority-queue-with-explanation/?envType=study-plan-v2&envId=top-interview-150