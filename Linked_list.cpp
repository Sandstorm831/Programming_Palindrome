#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int N;
    Node* next;
};

void displayLL(Node* head){
    while(head != NULL)
    {
        cout<<head->N<<endl;
        head = head->next;
    }
}
void headreplacer(Node** head, int value){
    Node* newer = new Node();
    newer->next = *head;
    newer->N = value;
    *head = newer;
}
void inserter(Node** head, int value, int embed){
    Node* midler = *head;
    Node* mid = new Node();
    while(midler->N != value){
        midler = midler->next;
    }
    mid->N = embed;
    mid->next = midler->next;
    midler->next = mid;
}
void deleter(Node** head, int value){
    Node* midler = *head;
    Node* backer = NULL;
    if(midler != NULL && midler->N == value)
    {
        *head = midler->next;
        delete midler;
        return;
    }
    else
    {
        while (midler != NULL && midler->N != value)
        {
            backer = midler; 
            midler = midler->next;
        }
        
        if(midler == NULL)return;
        backer->next = midler->next;
        delete midler;
        return;
    }
    
    while (midler->N != value)
    {
        midler =  midler->next;
    }
    if(midler->next == NULL) return;
    midler->next = midler->next->next;
    
}
int main()
{
    Node* head = NULL;
    Node* first = NULL;
    Node* second = NULL;
    first = new Node();
    second = new Node();
    head = new Node();
    head->N = 1;
    head->next = first;
    first->N = 2;
    first->next = second;
    second->N = 3;
    second->next = NULL;
    displayLL(head);
    //**************** Inserting a node ******************/
    Node* mid = new Node();
    mid->next = head->next;
    head->next = mid;
    mid->N = 5;
    cout<<"After inserting a node of value 5 between head and first node"<<endl;
    displayLL(head);
    //*************** Deleting a node ******************/
    mid->next = first->next;
    first->next = NULL;
    cout<<"After deleting the node first having value of 2"<<endl;
    displayLL(head);
    /*************** Functions to add a node at a particular position *************/
    cout<<"adding 8 after head node with the help of inserter a function"<<endl;
    inserter(&head,1,8);
    displayLL(head);
    cout<<"adding 8 after node 5 with the help of inserter a function"<<endl;
    inserter(&head,5,8);
    displayLL(head);
    cout<<"adding 9 after node 3 with the help of inserter a function"<<endl;
    inserter(&head,3,9);
    displayLL(head);
    /*********** Deleting element through a deleter function******************/
    cout<<"Testing if last element given then will the code work"<<endl;
    deleter(&head, 9);
    displayLL(head);
    cout<<"removing the element 1 which is head node"<<endl;
    deleter(&head, 1);
    displayLL(head);
    /**********************Replacing head node ********************************/
    cout<<"Adding 100 as new head and replacing the pointer of head pointer as new"<<endl;
    headreplacer(&head,100);
    displayLL(head);

}