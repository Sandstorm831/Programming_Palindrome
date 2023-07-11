// Question Link - https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/
// Solution

class Solution {
public:
    int answer = 0;

    void maxRequest(vector<vector<int>>& requests, vector<int>& indegree, int n, int index, int count) {
        if (index == requests.size()) {
            // Check if all buildings have an in-degree of 0.
            for (int i = 0; i < n; i++) {
                if (indegree[i]) {
                    return;
                }
            }
            
            answer = max(answer, count);
            return;
        }
        
        // Consider this request, increment and decrement for the buildings involved.
        indegree[requests[index][0]]--;
        indegree[requests[index][1]]++;
        // Move on to the next request and also increment the count of requests.
        maxRequest(requests, indegree, n, index + 1, count + 1);
        // Backtrack to the previous values to move back to the original state before the second recursion.
        indegree[requests[index][0]]++;
        indegree[requests[index][1]]--;
        
        // Ignore this request and move on to the next request without incrementing the count.
        maxRequest(requests, indegree, n, index + 1, count);
    }
        int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);
        maxRequest(requests, indegree, n, 0, 0);
        
        return answer;
    }
};
/* Both solutions are important */
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // vector<int> indegree(n, 0);
        // maxRequest(requests, indegree, n, 0, 0);
        
        // return answer;
        int nn = requests.size();
        vector<int> indegree(n+1,0);
        int ans = INT_MIN;
        for(int i=0; i<(1<<nn);i++)
        {
            int x = i;
            int j = 0;
            while(x>0)
            {
                int a = x&1; x = x>>1;
                if(a) 
                {
                    indegree[requests[j][0]]--;
                    indegree[requests[j][1]]++;
                }
                j++;
            }
            bool check=true;
            for(int i=0; i<indegree.size(); i++)
            {
                if(indegree[i]) check = false;
                indegree[i]=0;
            }
            if(check) ans = max(ans, __builtin_popcount(i));
        }
        return ans;
    }
};