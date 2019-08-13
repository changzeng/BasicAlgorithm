//
// Created by Liao Changzeng on 2019/8/13.
//

#include <iostream>

using namespace std;

struct Node{
    Node(int _val):nxt(nullptr),val(_val){};
    int val;
    Node *nxt;
};

Node *reverse(Node *head){
    Node *a = head;
    Node *b = nullptr;
    Node *c = nullptr;
    if(a) {
        b = a->nxt;
        a->nxt = nullptr;
    }
    if(b)
        c = b->nxt;
    while(b){
        b->nxt = a;
        a=b;
        b=c;
        if(c)
            c=c->nxt;
    }
    return a;
}

void release(Node *head){
    Node *nxt=head->nxt;
    while(head){
        delete head;
        head = nxt;
        if(nxt)
            nxt = nxt->nxt;
    }
}

int main() {
    Node *head = new Node(0);
    Node *cur = head;
    for(int i = 1; i <= 10; i++){
        cur->nxt = new Node(i);
        cur = cur->nxt;
    }


    head = reverse(head);

    cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->nxt;
    }
    cout<<endl;

    release(head);
}
