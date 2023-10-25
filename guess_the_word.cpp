// Question Link -https://leetcode.com/problems/guess-the-word/description/?envType=study-plan-v2&envId=google-spring-23-high-frequency
// solution 

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int score(string a, string b)
    {
        int counter=0;
        for(int i=0; i<a.size(); i++) 
        {
            if(a[i] == b[i]) counter++;
        }
        return counter;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> lm;
        int x=0;
        while(!words.empty())
        {
            int l = words.size()/2;
            string f = words[l];
            int sim = master.guess(f);
            cout<<words.size()<<" "<<x<<" "<<sim<<endl;
            if(sim == 6) return;
            for(int j=0; j<words.size();j++)
            {
                if(score(f, words[j]) == sim) lm.push_back(words[j]);
            }
            words = lm;
            lm.clear();
            cout<<words.size()<<endl;
        }
    }
};
/*
Explanation - https://leetcode.com/problems/guess-the-word/solutions/134087/elimination-histogram/?envType=study-plan-v2&envId=google-spring-23-high-frequency
although this result is when we haven't used the histogram method, just initial statement