#include<bits/stdc++.h>

class node{
    public:
    int data;
    node* next;
    node(int data);
};

node::node(int data){
    this->data=data;
    this->next=NULL;
}

void print(node*& head){
    node* curr = head;
    while(curr!=NULL){
        std::cout<<curr->data<<" ";
        curr=curr->next;
    }std::cout<<std::endl;
}

void segregateplaces(int& size){
    int data;
    std::cin>>data;
    node* head = new node(data);
    node* curr = head;
    for (int i=1; size>i; ++i){
        std::cin>>data;
        curr->next = new node(data);
        curr = curr->next;
    }
    node* temp = head;
    node* dum;
    for(int i=0; (size)/2>i; ++i){
        dum=temp->next->next;
        curr->next=temp->next;
        temp->next=dum;
        curr->next->next=NULL;
        curr=curr->next;
        temp=temp->next;
    }temp=head;
    std::cout<<"\nModified Linked list --> \n";
    print(temp);
}

int main(){

    int size;
    std::cout<<"\n      Enter the size of the singly linked list --> \n";
    std::cin>>size;
    if (size==0) std::cout<<"\nEmpty linked list\n";
    else segregateplaces(size);

    return 0;
}