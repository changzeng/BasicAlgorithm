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
    ~Node(){
        if(left != nullptr)
            delete left;
        if(right != nullptr)
            delete right;
    }
};

void pos_traverse(Node *root){
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

void pre_traverse(Node *root){
    stack<Node *> array;
    Node *cur_node=nullptr;
    array.push(root);
    while(!array.empty() || cur_node != nullptr){
        if(cur_node == nullptr){
            cur_node = array.top();
            array.pop();
        }else{
            cout<<cur_node->val<<endl;
            array.push(cur_node->right);
            cur_node=cur_node->left;
        }
    }
}

void mid_traverse(Node *root){
    // TODO: traverse error
    stack<Node *> array;
    Node *cur_node=root;
    array.push(root);
    while(!array.empty() || cur_node!=nullptr){
        if(cur_node == nullptr){
            cur_node = array.top();
            array.pop();
            cout<<cur_node->val<<endl;
            cur_node = cur_node->right;
        }else{
            array.push(cur_node);
            cur_node = cur_node->left;
        }
    }
}

void s_traverse(Node *root){
    stack<Node *> cur_layer;
    stack<Node *> nxt_layer;
    int layer=0;
    cur_layer.push(root);
    while(!cur_layer.empty()){
        while(!cur_layer.empty()) {
            Node *node = cur_layer.top();
            cur_layer.pop();
            if(node == nullptr)
                continue;
            cout<<node->val<<endl;
            if (layer % 2 == 0) {
                nxt_layer.push(node->right);
                nxt_layer.push(node->left);
            }else{
                nxt_layer.push(node->left);
                nxt_layer.push(node->right);
            }
        }
        swap(cur_layer, nxt_layer);
        layer++;
    }
}

//int main(){
//    Node *root = new Node(1);
//    root->left = new Node(2);
//    root->right = new Node(3);
//    root->left->left = new Node(4);
//    root->left->right = new Node(5);
//    root->right->left = new Node(6);
//    root->right->right = new Node(7);
//    root->left->left->left = new Node(9);
//    root->left->left->right = new Node(10);
//    root->left->right->right = new Node(11);
//
////    pre_traverse(root);
////    mid_traverse(root);
////    pos_traverse(root);
//    s_traverse(root);
//
//    delete root;
//    return 0;
//}
