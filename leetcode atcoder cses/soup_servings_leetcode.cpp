// Question Link - https://leetcode.com/problems/soup-servings/description/
// solution 

class Solution {
public:
    vector<int> a = {100, 75, 50, 25};
    vector<int> b = {0, 25, 50, 75};
    unordered_map<string, double> ump;
    double recursor(double aa, double bb)
    {
        string s = to_string(aa)+"|"+to_string(bb);
        if(aa == 0 || bb == 0)
        {
            if(aa == 0 && bb == 0) return (double)(0.5);
            else if(aa == 0) return (double)(1);
            else if(bb == 0) return (double)(0);
            else return (double)(0);
        }
        else if(ump.find(s) != ump.end()) return ump[s];
        else
        {
            double prob = 0;
            for(int i=0;i<4; i++)
            {
                prob += 0.25 * recursor(max((double)(aa-a[i]), (double)(0)), max((double)(bb-b[i]), (double)(0)));
            }
            return ump[s] = prob;
        }
    }
    double soupServings(int n) {
        if(n>4800) return double(1);
        ump.clear();
        double prob = 0;
        for(int i=0;i<4; i++)
        {
            prob += 0.25 * recursor(max((double)(n-a[i]), (double)(0)), max((double)(n-b[i]), (double)(0)));
        }
        return double(prob);
    }
};