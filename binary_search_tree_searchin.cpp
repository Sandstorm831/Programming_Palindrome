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
void searher(node* head, int val, bool& hell){
    if(head == NULL) return;
    if(head->data ==  val) {hell = true; return;}
    else if(head->data > val) searher(head->left, val, hell);
    else searher(head->right, val, hell);
}
int main()
{
    int root;
    cout<<"Enter the root node data, -1 for empty node"<<endl;
    cin>>root;
    node* head = binarytreeformer(root);

    /*
    Following tree is constructed;
                         4
                       /   \
                      2     6
                     / \   / \
                    1   3  5  7
    */
   bool hell = false;
   searher(head,8, hell );
   cout<<hell;
}