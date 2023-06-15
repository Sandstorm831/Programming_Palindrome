// Question lInk - https://www.interviewbit.com/problems/hotel-reviews/
// Solution

struct Trie{
    vector<Trie*> edges;
    bool isend;
    Trie()
    {
        isend=false;
        edges.resize(26,NULL);
    }
};
void Trie_insert(Trie* head, string s)
{
    int n = s.length();
    Trie* curr = head;
    for(int i=0; i<n; i++)
    {
        if(!curr->edges[s[i]-'a']) curr->edges[s[i]-'a'] = new Trie();
        curr = curr->edges[s[i]-'a'];
    }
    curr->isend = true;
}
bool is_present(Trie* head, string word)
{
    Trie* curr = head;
    for(int i=0; i<word.size(); i++)
    {
        if(!curr->edges[word[i]-'a']) return false;
        curr = curr->edges[word[i]-'a'];
    }
    return curr->isend;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    Trie* obj = new Trie();
    stringstream s(A);
    string word;
    while(getline(s,word,'_'))
    {
        Trie_insert(obj, word);
       
    }
    vector<int> ans;
    vector<pair<int,int>> tmp;
    int n=B.size();
    for(int i=0;i<n;i++)
    {
        stringstream s(B[i]);
        string word;
        int cnt=0;
        while(getline(s,word,'_'))
        {
            if(is_present(obj, word))
            cnt++;
        }
        tmp.push_back({-cnt,i});
    }
    sort(tmp.begin(),tmp.end());
    for(auto &x: tmp)
    ans.push_back(x.second);
   
    return ans;
}