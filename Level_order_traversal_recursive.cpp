// 
// This algorithm have time complexity O(N^2) whereas level_order_traversal_queue.cpp have algorithm with time complexity O(N)
// 
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
int maxheightofbinarytree(node* head)
{
    if(head == NULL) return 0;
    return max(maxheightofbinarytree(head->left), maxheightofbinarytree(head->right)) + 1;
}
void leveltraversal(node* head, int level, vector<int>& ansy) 
{
    if(head ==  NULL) return ;
    else if(level == 1){
        ansy.push_back(head->data);
        return ;
    }
    else{
        leveltraversal(head->left, level-1, ansy);
        leveltraversal(head->right, level-1, ansy);
    }
}

int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    vector<int> ansy;
    int hite = maxheightofbinarytree(head);
    for (int i = 1; i <= hite ; i++)
    {
        leveltraversal(head, i, ansy);
    }
    for (int i = 0; i < ansy.size(); i++)
    {
        cout<<ansy[i]<<" ";
    }   
}