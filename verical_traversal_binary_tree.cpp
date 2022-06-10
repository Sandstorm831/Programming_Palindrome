// Problem Link - https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
/** Problem Solution Function --------------------------------------------------------------------------+
 * Definition for binary tree                                                                           |    
 * struct TreeNode {                                                                                    |
 *     int val;                                                                                         |                          
 *     TreeNode *left;                                                                                  |    
 *     TreeNode *right;                                                                                 |                                        
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}                                             |                                                 
 * };                                                                                                   |
 *                                                                                                      |
void mapmaker(TreeNode* head, map<int,multimap<int, int>>& m, int depth, int dist ){     <--------------+
    if(head == NULL) return;
    if(m.count(dist) == 0)
    {
        multimap<int,int> tempo;
        tempo.insert(pair<int,int>(depth, head->val));
        m[dist] = tempo;
    }
    else
    {   
        m[dist].insert(pair<int,int>(depth, head->val));
    }
    mapmaker(head->left, m, depth+1, dist-1);
    mapmaker(head->right, m, depth+1, dist+1);
}
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> turner;
    map<int,multimap<int,int>> m;
    mapmaker(A, m, 0,0);
    map<int,multimap<int,int>>::iterator it;
    map<int,int>::iterator ct;
    for ( it = m.begin(); it != m.end(); it++)
    {
        vector<int> gunner;
        for ( ct = m[it->first].begin(); ct != m[it->first].end(); ct++)
        {
            gunner.push_back(ct->second);
        }
        turner.push_back(gunner);
    }
    return turner;
}
*/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node* binarytreeformer(int data){
    if(data == -1) return NULL;
    node* ndoe = new node(data);
    int leftnode, rightnode;
    cout<<"enter data of left node of "<<data<<endl;
    cin>>leftnode;
    ndoe->left = binarytreeformer(leftnode);
    cout<<"enter data of right node of "<<data<<endl;
    cin>>rightnode;
    ndoe->right = binarytreeformer(rightnode);
    return ndoe;
}
void mapmaker(node* head, map<int,multimap<int, int>>& m, int depth, int dist ){
    if(head == NULL) return;
    if(m.count(dist) == 0)
    {
        multimap<int,int> tempo;
        tempo.insert(pair<int,int>(depth, head->data));
        m[dist] = tempo;
    }
    else
    {   
        m[dist].insert(pair<int,int>(depth, head->data));
    }
    mapmaker(head->left, m, depth+1, dist-1);
    mapmaker(head->right, m, depth+1, dist+1);
}
vector<int> verticalTraverser(node* head){
    vector<int> turner;
    map<int,multimap<int,int>> m;
    mapmaker(head, m, 0,0);
    map<int,multimap<int,int>>::iterator it;
    map<int,int>::iterator ct;
    for ( it = m.begin(); it != m.end(); it++)
    {
        for ( ct = m[it->first].begin(); ct != m[it->first].end(); ct++)
        {
            turner.push_back(ct->second);
        }
        
    }
    return turner;
}

int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    vector<int> solv = verticalTraverser(head);
    for (int i = 0; i < solv.size(); i++)
    {
        cout<<solv[i]<<" ";
    }
}