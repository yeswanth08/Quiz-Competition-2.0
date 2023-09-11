#include<bits/stdc++.h>

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data);
};

node::node(int data){
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
}

int maxpairsum(int& data, int& size){
    int value;
    node* head = new node(data);
    node* tail = head;
    for(int i=1; size>i; ++i){
        std::cin>>value;
        tail->next = new node(value);
        tail->next->prev = tail;
        tail=tail->next;
    }
    node* curr = head;
    int ans=INT_MIN;
    int sum;
    while(curr!=tail){
        sum=curr->data+tail->data;
        ans=std::max(sum,ans);
        curr=curr->next;
        tail=tail->prev;
    }return ans;
}

int main(){

    int size,data;
    std::cout<<"Enter the size of the linked list --> ";
    std::cin>>size>>data;
    std::cout<<"Max_PairSum --> "<<maxpairsum(data,size);

    return 0;
}