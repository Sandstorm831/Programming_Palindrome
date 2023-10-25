// Question Link - https://leetcode.com/problems/add-binary/description/?envType=study-plan-v2&envId=top-interview-150
// solution 

class Solution {
public:
    string addBinary(string a, string b) {
        int ia = a.size()-1;
        int ib = b.size()-1;
        int rem = 0;
        string ans="";
        while(ia>=0 && ib>=0)
        {
            int x = a[ia]-'0' + b[ib]-'0'+rem;
            ans += to_string(x%2);
            rem = x/2;
            ia--;
            ib--;
        }
        while(ia>=0)
        {
            int x = a[ia]-'0' +rem;
            ans += to_string(x%2);
            rem = x/2;
            ia--; 
        }
        while(ib>=0)
        {
            int x =  b[ib]-'0'+rem;
            ans += to_string(x%2);
            rem = x/2;
            ib--;
        }
        if(rem) ans += to_string(rem);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};