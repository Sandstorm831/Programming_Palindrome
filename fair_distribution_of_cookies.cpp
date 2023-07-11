// Question LInk - https://leetcode.com/problems/fair-distribution-of-cookies/description/
// Solution 


class Solution {
public:
    int minn;
    void recursor(vector<int>& cookies, vector<int>& v, int k, int curr, int fair)
    {
        if(curr == cookies.size()-1)
        {
            for(int i=0;i<k; i++)
            {
                v[i]+=cookies[curr];
                int xx = INT_MIN;
                for(int j=0; j<v.size(); j++) xx = max(xx, v[j]);
                minn = min(minn, xx);
                v[i]-=cookies[curr];
            }
        }
        else
        {
            for(int i=0; i<k; i++)
            {
                v[i]+=cookies[curr];
                recursor(cookies, v, k, curr+1, fair);
                v[i]-=cookies[curr];
                if(v[i]==0) break;
            }
        }

    }
    int distributeCookies(vector<int>& cookies, int k) {
        int sum = accumulate(cookies.begin(),cookies.end(),0);
        auto n = cookies.size();
        sort(cookies.begin(),cookies.end(),greater<int>());
        int fair = sum/k;
        vector<int> v(k,0);
        minn = INT_MAX;
        recursor(cookies, v, k, 0, fair);
        return minn;
    }
};