// Question Link - https://leetcode.com/problems/filling-bookcase-shelves/description/
// solution 

class Solution {
public:
    vector<int> dp;
    int recursor(vector<vector<int>>& books, int W, int index)
    {
        if(index >= books.size()) return 0;
        else if(dp[index] != -1) return dp[index];
        else
        {
            int minn = INT_MAX;
            int maxer = books[index][1];
            int width = books[index][0];
            int k = 0;
            while(width <= W)
            {
                k++;
                minn = min(minn, maxer+recursor(books, W, index+k));
                if(index+k < books.size())
                {
                    maxer = max(maxer, books[index+k][1]);
                    width += books[index+k][0];
                }
                else break;
            }
            return dp[index] = minn;
        }
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp.clear(); dp.resize(books.size()+1, -1);
        return recursor(books, shelfWidth, 0);
    }
};