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

int main(){

    int size,data,rotate;
    std::cout<<"\nEnter the size of the singly linked list --> \n";
    std::cin>>size;
    if (size==0) std::cout<<"\nEmpty linked list\n";
    else{
        std::cin>>data;
        node* head = new node(data);
        node* curr = head;
        for(int i=1; size>i; ++i){
            std::cin>>data;
            curr->next = new node(data);
            curr = curr->next;
        }curr->next = head;
        std::cout<<"Enter the no.of times to rotate the given linked list --> \n";
        std::cin>>rotate;
        curr=head;
        int i;
        (rotate%2==0) ? i=0 : i=1;
        for (i; rotate>i; ++i){
            curr=curr->next;
        }node* dum = curr->next;
        curr->next=NULL;
        print(dum);
    }

    return 0;
}