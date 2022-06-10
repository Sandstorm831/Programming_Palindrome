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
void mapmaker(node* head, map<int,pair<int,int>>& m, int depth, int dist ){
    if(head == NULL) return;
    if(m.count(dist) == 0)
    {
        m[dist] = make_pair(head->data, depth);
    }
    else if(m[dist].second > depth)
    {
        m[dist] = make_pair(head->data, depth);
    }
    mapmaker(head->left, m, depth+1, dist-1);
    mapmaker(head->right, m, depth+1, dist+1);
}
vector<int> topviewer(node* head){
    vector<int> turner;
    map<int,pair<int,int>> m;
    mapmaker(head, m, 0,0);
    map<int,pair<int,int>>::iterator it;
    for ( it = m.begin(); it != m.end(); it++)
    {
        turner.push_back(it->second.first);
    }
    return turner;
}

int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    vector<int> solv = topviewer(head);
    for (int i = 0; i < solv.size(); i++)
    {
        cout<<solv[i]<<" ";
    }
    
}