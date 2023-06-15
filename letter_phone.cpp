// Question Link - https://www.interviewbit.com/problems/letter-phone/
// Solution

vector<vector<int>> dict;
vector<string> ans;
void recursor(string A, string t, int index)
{
    if(index > A.length()) return;
    else if(index == A.length())
    {
        ans.push_back(t);
        return;
    }
    else
    {
        if(A[index]-'0' == 0 || A[index]-'0' == 1)
        {
            if(A[index]-'0' == 0)
            {
                t += '0';
                recursor(A, t, index+1);
                t.pop_back();
            }
            else
            {
                t+='1';
                recursor(A, t, index+1);
                t.pop_back();
            }
            return;
        }
        for(int j=0;j<dict[A[index]-'0'].size(); j++)
        {
            t += dict[A[index]-'0'][j]+'a';
            recursor(A, t,index+1);
            // cout<<t<<endl;
            t.pop_back();
        }
    }
    return;
}
vector<string> Solution::letterCombinations(string A) {
    dict.clear();
    dict.resize(10, vector<int> ());
    dict[0].push_back(0);
    dict[1].push_back(1);
    dict[2].push_back(0);dict[2].push_back(1);dict[2].push_back(2);
    dict[3].push_back(3);dict[3].push_back(4);dict[3].push_back(5);
    dict[4].push_back(6);dict[4].push_back(7);dict[4].push_back(8);
    dict[5].push_back(9);dict[5].push_back(10);dict[5].push_back(11); 
    dict[6].push_back(12);dict[6].push_back(13);dict[6].push_back(14);
    dict[7].push_back(15);dict[7].push_back(16);dict[7].push_back(17);dict[7].push_back(18);
    dict[8].push_back(19);dict[8].push_back(20);dict[8].push_back(21);
    dict[9].push_back(22);dict[9].push_back(23);dict[9].push_back(24);dict[9].push_back(25);
    int index=0;
    string t="";
    ans.clear();
    recursor(A, t, index);
    sort(ans.begin(), ans.end());
    return ans;
}
