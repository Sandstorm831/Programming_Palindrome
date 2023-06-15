// Question link - https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
// Solution 

string Solution::solve(string A) {
    vector<int> v(26,0);
    string b = "";
    queue<int> q;
    for(int i=0; i<A.size(); i++)
    {
        int ck = A[i]-'a';
        v[ck]++;
        if(v[ck]==1) q.push(ck);
        while((!q.empty())&&(v[q.front()]>1)) q.pop();
        if(q.empty()) b += "#";
        else b += q.front() + 'a';
    }
    return b;
}
