#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
};
node* everreverser(node** head){
    vector<int> numlock;
    node* count = *head;
    int counter = 0;
    while(count != NULL)
    {
        counter++;
        if(counter%2 == 0) numlock.push_back(count->val);
        count = count->next;
    }
    count = *head;counter = 0;
    while (count != NULL)
    {
        counter++;
        if (counter%2==0)
        {
            count->val = numlock[numlock.size()-1];
            numlock.pop_back();
        }
        count = count->next;
    }
    return *head;
}
void displayLL(node* head){
    cout<<"***********************************"<<endl;
    while(head != NULL)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
    cout<<"***********************************"<<endl;
}
int main()
{
    node* head = new node();
    node* first = new node();
    node* second  = new node();
    node* third = new node();
    head->val = 1;
    head->next = first;
    first->val = 2;
    first->next = second;
    second->val =3;
    second->next = third;
    third->val = 4;
    third->next = NULL;
    displayLL(head);
    node* ketm = everreverser(&head);
    displayLL(ketm);
}