//
// Created by Liao Changzeng on 2019/3/6.
//

#include <iostream>
#include <stack>

using namespace std;

struct Node{
    Node(int _val){val=_val;};
    Node *left = nullptr;
    Node *right = nullptr;
    bool is_visit = false;
    int val;
    void destruct(Node *n){
        if(n == nullptr)
            return;
        destruct(n->left);
        destruct(n->right);
        cout<<n->val<<endl;
        delete n;
    }
    ~Node(){
        destruct(left);
        destruct(right);
    }
};

void post_traverse(Node *root){
    stack<Node *> array;
    Node *cur_node=root;
    while(!array.empty() || cur_node != nullptr){
        if(cur_node == nullptr){
            cur_node = array.top();
            if(cur_node->is_visit){
                cout<<cur_node->val<<endl;
                array.pop();
                cur_node = nullptr;
            }else{
                cur_node->is_visit=true;
                cur_node = cur_node->right;
            }
        }else{
            array.push(cur_node);
            cur_node = cur_node->left;
        }
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    delete root;
    return 0;
}
