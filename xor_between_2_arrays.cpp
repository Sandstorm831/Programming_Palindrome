// Question Link - https://www.interviewbit.com/problems/xor-between-two-arrays/
// solution 

struct Trie{
    vector<Trie*> edges;
    bool isend;
    Trie()
    {
        edges.resize(2,NULL);
        isend=false;
    }
};
void insert(Trie* head, int num)
{
    Trie* curr = head;
    for(int i=31; i>=0; i--)
    {
        int index = num & (1<<i);
        if(index > 0) index=1;
        else index=0;
        if(!curr->edges[index]) curr->edges[index] = new Trie();
        curr = curr->edges[index];
    }
    curr->isend=true;
}
int maxx;
void maxfinder(int num, Trie* head)
{
    Trie* curr = head;
    int res=0;
    for(int i=31; i>=0; i--)
    {
        int index = num & (1<<i);
        if(index>0) index=1;
        else index=0;
        if(!curr->edges[index^1])
        {
            curr = curr->edges[index];
        }
        else
        {
            res |= (1<<i);
            curr = curr->edges[index^1];
        }
    }
    maxx = max(maxx, res);
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    maxx = INT_MIN;
    Trie *head = new Trie();
    for(int i=0; i<A.size(); i++) insert(head, A[i]);
    for(int i=0; i<B.size(); i++) maxfinder(B[i], head);
    return maxx;
    
}
