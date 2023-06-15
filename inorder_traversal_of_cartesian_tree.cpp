// Question Link - https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
// Solution

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> st;
void construct_s_tree(vector<int> &A,int l,int r,int index)
{
   
    if(l==r)
    {
        st[index]=A[l];
        return;
    }
    int mid= (l+r)/2;
    construct_s_tree(A,l,mid,2*index);
    construct_s_tree(A,mid+1,r,2*index+1);
    st[index]=max(st[2*index],st[2*index+1]);
   
}
int query(int l, int h,int a,int b,int index)
{
    if(l>=a && h<=b) return(st[index]);
    if(l>b||h<a) return(INT_MIN);
    int mid=(l+h)/2;
    return(max(query(l,mid,a,b,index*2),query(mid+1,h,a,b,index*2+1)));
}
TreeNode *construct_tree(vector<int> &A, int ini,int fin,unordered_map<int,int> &un_mp)
{
    int ind=0;
    if(ini>fin)
        return(NULL);
    int ma=query(0,A.size()-1,ini,fin,1);
    TreeNode *root = new TreeNode(ma);
    root->left  = construct_tree(A,ini,un_mp[ma]-1,un_mp);
    root->right = construct_tree(A,un_mp[ma]+1,fin,un_mp);
    return(root);
   
}
TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    st.clear();
    st.resize(4*n,0);
    unordered_map<int,int> un_mp;
    for(int i=0 ;i<n;i++)
    {
        un_mp[A[i]]=i;
    }
    construct_s_tree(A,0,n-1,1);
    return construct_tree(A,0,n-1,un_mp);
}
