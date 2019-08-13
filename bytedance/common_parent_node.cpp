//
// Created by Liao Changzeng on 2019/8/13.
//

#include <iostream>

using namespace std;

struct Node{
    Node(int _val):val(_val),left(nullptr),right(nullptr){};
    Node *left;
    Node *right;
    int val;
};

int find_common_parent(Node* root, int val1, int val2, int &res){
    if(!root)
        return -1;
    int left_val = find_common_parent(root->left, val1, val2, res);
    if(res != -1)
        return -2;
    int right_val = find_common_parent(root->right, val1, val2, res);
    if(res != -1)
        return -2;

    if(left_val == val1 && right_val == val2)
        res = root->val;
    else if(left_val == val2 && right_val == val1)
        res = root->val;
    else if(left_val == val1 || left_val == val2)
        return left_val;
    else if(right_val == val1 || right_val == val2)
        return right_val;
    else if(root->val == val1 || root->val == val2)
        return root->val;
    return -1;
}

int find_common_parent_elegant(Node *root, int val1, int val2, int &res){
    if(!root)
        return 0;
    int left_status = find_common_parent_elegant(root->left, val1, val2, res);
    if(left_status == 3)
        return 3;
    int right_status = find_common_parent_elegant(root->right, val1, val2, res);
    if(right_status == 3)
        return 3;

    int ret_status=0;
    if(left_status == 1 && right_status == 2)
        ret_status = 3;
    else if(left_status == 2 && right_status == 1)
        ret_status = 3;
    else if(left_status == 1 && root->val == val2)
        ret_status = 3;
    else if(left_status == 2 && root->val == val1)
        ret_status = 3;
    else if(right_status == 1 && root->val == val2)
        ret_status = 3;
    else if(right_status == 2 && root->val == val1)
        ret_status = 3;
    else if(right_status != 0)
        ret_status = right_status;
    else if(left_status != 0)
        ret_status = left_status;
    else if(root->val == val1)
        ret_status = 1;
    else if(root->val == val2)
        ret_status = 2;
    if(ret_status == 3)
        res = root->val;

    return ret_status;
}

void release(Node *root){
    if(!root)
        return;
    release(root->left);
    release(root->right);
    delete root;
}

int main(){
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    int res1=-1, res2=-1;
    int val1=2, val2=6;
    find_common_parent(root, val1, val2, res1);
    find_common_parent_elegant(root, val1, val2, res2);

    cout<<res1<<" "<<res2<<endl;
    release(root);
}
