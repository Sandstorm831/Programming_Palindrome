// Problem Link - https://www.interviewbit.com/problems/kth-node-from-middle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
ListNode* Solution::solve(ListNode* A) {
    vector<int> numlock;
    ListNode* count = A;
    int counter = 0;
    while(count != NULL)
    {
        counter++;
        if(counter%2 == 0) numlock.push_back(count->val);
        count = count->next;
    }
    count = A;counter = 0;
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
    return A;
}

*************************************************************************************************************
An alternate solution -------------------------------+
ListNode * reverseList(ListNode * head){       <-----+         
    if(!head||!head->next)return head;
    ListNode * previous = nullptr;
    ListNode * next ;
    while(head){
        next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;
} 
 
ListNode* Solution::solve(ListNode* A) {
    if(!A||!A->next||!A->next->next||!A->next->next->next)return A;
    //cout<<"working on it "<<endl;
    ListNode * head = A;
    ListNode * slow = A;
    ListNode * fast = A->next;
    ListNode * brk = nullptr;
    while(fast&&fast->next){
        //cout<<"slow is "<<slow->next->val<<" while fast is "<<fast->val<<endl;
        slow = slow->next ;
        fast = fast->next->next;
    }
    bool even = fast?false:true;
    brk = slow;
    //cout<<"slow is "<<slow->val<<endl;
    //cout<<"even is "<<even<<endl;
    fast = reverseList(slow->next);
    //cout<<"fast is "<<fast->val<<endl;
    slow = A->next;
    head = fast;
    if(even)fast = fast->next;
    //cout<<"slow is set to "<<slow->val<<endl;
    even = true;
    while(fast){
        if(even){
            swap(slow->val,fast->val);
        }
        even = !even;
        slow = slow->next;
        fast = fast->next;
    }
    brk->next = reverseList(head);
    brk = brk->next;
    //cout<<"brk point is connected to "<<brk->val<<endl;
    return A;
}
*/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
};
int nodefromiddle(node* head, int B){
    node* count = head;
    vector<int> numlock;
    int size = 0;
    while(count!= NULL)
    {
        size++;
        numlock.push_back(count->val);
        count = count->next;
    }
    int midnode = size/2;
    if(midnode-B>=0) return numlock[midnode-B];
    else return -1;

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
int main(){
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
    cout<<nodefromiddle(head, 1);

}
