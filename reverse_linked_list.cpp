#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int n;
    node* next;
};
node* reverser(node** head){
    node* prely = *head;
    node* backly = NULL;
    while(prely != NULL)
    {
        node* tempo = prely->next;
        prely->next = backly;
        backly = prely;
        prely = tempo;
    }
    return backly;
}
void displayLL(node* head){
    node* hell = head;
    while (hell != NULL)
    {
        cout<<hell->n<<endl;
        hell = hell->next;
    }
    
}
int main(){
    node* head = new node();
    node* first = new node();
    node* second = new node();
    node* third = new node();
    head->n = 12;
    head->next = first;
    first->n = 122;
    first->next = second;
    second->n = 244;
    second->next = third;
    third->n =648;
    third->next = NULL;
    displayLL(head);
    head = reverser(&head);
    cout<<"Let's see if the liked list is reversed or not"<<endl;
    displayLL(head);


}