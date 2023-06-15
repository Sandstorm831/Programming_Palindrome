// Question Link - https://www.interviewbit.com/problems/substring-concatenation/
// Solution

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int aa = B[0].size();
    int bb = B.size();
    int ts = aa*bb;
    unordered_map<string,int> mp,ump;
    for(int i=0; i<B.size(); i++)
    {
        if(ump.find(B[i]) == ump.end()) ump[B[i]]=1;
        else ump[B[i]]++;
        mp[B[i]]=0;
    }
    unordered_map<string,int> temp;
    vector<int> ans;
    for(int i=0; i+ts<=A.size(); i++)
    {
        temp.clear();
        temp = ump;
        if(mp.find(A.substr(i,aa)) != mp.end())
        {
            int j = i;
            int cnt = bb;
            while(cnt>0 && temp.find(A.substr(j,aa))!=temp.end())
            {
                if(temp[A.substr(j,aa)] > 0) 
                {
                    temp[A.substr(j,aa)]--;
                    j += aa;
                    cnt--;
                }
                else break;
            }
            if(cnt == 0) ans.push_back(i);
        }
    }
    return ans;
}
