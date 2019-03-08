//
// Created by Liao Changzeng on 2019/3/8.
//

#include <iostream>

using std::cout;
using std::endl;

struct LinkedNode{
    explicit LinkedNode(int v){
        this->val=v;
        this->nxt= nullptr;
    }
    LinkedNode *nxt;
    int val;
    ~LinkedNode(){
        if(this->nxt != nullptr)
            delete this->nxt;
    }
};

LinkedNode *order_merge(LinkedNode *list_1, LinkedNode *list_2){
    LinkedNode *ptr1 = list_1;
    LinkedNode *ptr2 = list_2;
    LinkedNode *res = new LinkedNode(-1);
    LinkedNode *cur = res;
    while(ptr1 != nullptr && ptr2 != nullptr){
        if(ptr1->val > ptr2->val){
            cur->nxt = ptr2;
            ptr2 = ptr2->nxt;
        }else{
            cur->nxt = ptr1;
            ptr1 = ptr1->nxt;
        }
        cur = cur->nxt;
        // cout<<cur->val<<endl;
    }
    while(ptr1 != nullptr){
        cur->nxt = ptr1;
        ptr1 = ptr1->nxt;
        cur = cur->nxt;
    }
    while(ptr2 != nullptr){
        cur->nxt = ptr2;
        ptr2 = ptr2->nxt;
        cur = cur->nxt;
    }
    cur->nxt = nullptr;
    cur = res;
    res = res->nxt;
    cur->nxt = nullptr;
    delete cur;
    return res;
}

int main(){
    auto linked_list_1 = new LinkedNode(2);
    linked_list_1->nxt = new LinkedNode(3);
    linked_list_1->nxt->nxt = new LinkedNode(5);

    auto linked_list_2 = new LinkedNode(1);
    linked_list_2->nxt = new LinkedNode(4);
    linked_list_2->nxt->nxt = new LinkedNode(6);

    LinkedNode *merge_list = order_merge(linked_list_1, linked_list_2);
    LinkedNode *cur_node = merge_list;
    while(cur_node != nullptr){
        cout<<cur_node->val<<endl;
        cur_node = cur_node->nxt;
    }

    delete linked_list_1;
    delete linked_list_2;
}

