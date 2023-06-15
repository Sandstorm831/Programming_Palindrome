// Question Link - https://www.interviewbit.com/problems/window-string/
// Solution 

string Solution::minWindow(string A, string B) {
    unordered_map<char, int> str, pat, orig;
    if(A.size()<B.size()) return "";
    int tg=B.size();
    int minn = INT_MAX;
    int stind=-1;
    for(int i=0; i<B.size(); i++)
    {
        if(pat.find(B[i]) == pat.end()) pat[B[i]]=1;
        else pat[B[i]]++;
    }
    orig = pat;
    int start = 0;
    int count=0;
    for(int i=0; i<A.size(); i++)
    {
        if(pat.find(A[i]) != pat.end())
        {
            if(str.find(A[i]) == str.end()) 
            {
                str[A[i]]=1;
                count++;
            }
            else if(str[A[i]] < pat[A[i]])
            {
                str[A[i]]++;
                count++;
            }
            else if(str[A[i]] >= pat[A[i]]) str[A[i]]++;
            if(count == tg)
            {
                while(orig.find(A[start]) == orig.end() || str[A[start]] > orig[A[start]] )
                {
                    if(orig.find(A[start]) != orig.end() && str[A[start]] > orig[A[start]]) 
                    {
                        str[A[start]]--;
                    }

                    start++;

                }
                if(i-start+1 < minn)
                {
                    minn = i-start+1;
                    stind = start;
                }
            }
        }
    }
    string tt = "";
    if(stind == -1) return "";
    else
    {
        return A.substr(stind, minn);
    }
}
