// Question Link - https://www.interviewbit.com/problems/valid-ip-addresses/
// Solution

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    for(int i=1; i<=3 ; i++)
    {
        for(int j=1; j<=3; j++)
        {
            for(int k=1; k<=3 ; k++)
            {
                for(int l=1; l<=3 ; l++)
                {
                    if(i+j+k+l == A.size())
                    {
                        string a = A.substr(0,i);
                        string b = A.substr(i, j);
                        string c = A.substr(i+j, k);
                        string d = A.substr(i+j+k, l);
                        if((a[0] == '0' && a.size()>1) || (b[0] == '0'&& b.size()>1) || (c[0] == '0' && c.size()>1) || (d[0] == '0' && d.size()>1)) continue;
                        else if(stoi(a) <= 255 && stoi(b)<=255 && stoi(c) <=255 && stoi(d) <= 255)
                        {
                            string s = a; s += '.'; s+=b; s+='.'; s+=c; s+='.'; s+=d;
                            ans.push_back(s);
                        }
                    }
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
