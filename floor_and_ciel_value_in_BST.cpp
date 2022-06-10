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

void floorcieler(node* head,int& floor, int& ciel, int target){
    if(head == NULL) return;
    floorcieler(head->left, floor, ciel, target);
    if(head->data > floor && head->data< target) floor = head->data;
    else if(head->data < ciel && head->data > target) ciel = head->data;
    floorcieler(head->right, floor, ciel, target);
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);
    int floor = INT_MIN;
    int ciel = INT_MAX;
    int target = 5;
    floorcieler(head, floor, ciel, target);
    cout<<floor<<" <- this is floor and here is ciel -> "<<ciel;
    

}