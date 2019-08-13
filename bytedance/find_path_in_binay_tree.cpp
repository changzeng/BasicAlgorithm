//
// Created by Liao Changzeng on 2019/8/13.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node{
    Node(int _val):val(_val),left(nullptr),right(nullptr){};
    Node *left;
    Node *right;
    int val;
};

typedef vector<int> Path;

int find_path_in_binary_tree(Node *root, int start, int end, Path &path1, Path &path2, Path &path){
    if(!root)
        return 0;
    int left = find_path_in_binary_tree(root->left, start, end, path1, path2, path);
    if(!path.empty())
        return 3;
    int right = find_path_in_binary_tree(root->right, start, end, path1, path2, path);
    if(!path.empty())
        return 3;

    int status=0;
    if(left==1&&right==2 || right==1&&left==2){
        for(int i=path1.size()-1; i>=0; i--)
            path.push_back(path1[i]);
        path.push_back(root->val);
        for(int i=0; i<path2.size(); i++)
            path.push_back(path2[i]);
        return 3;
    }else if((left==1||right==1)&&root->val==end){
        path=path1;
        path.push_back(root->val);
        return 3;
    }else if((left==2||right==2)&&root->val==start){
        path.push_back(root->val);
        for(int i=path2.size()-1; i>=0; i--)
            path.push_back(path2[i]);
        return 3;
    }else if(root->val==start){
        status = 1;
    }else if(root->val==end){
        status = 2;
    }
    status = max(status, max(left, right));

    if(status == 1)
        path1.push_back(root->val);
    if(status == 2)
        path2.push_back(root->val);

    return status;
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

    Path path1, path2, path;

    find_path_in_binary_tree(root, 0, 6, path1, path2, path);

    for(auto val:path)
        cout<<val<<" ";
    cout<<endl;

    release(root);

    return 0;
}
