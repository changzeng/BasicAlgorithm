#include <iostream>
#include <vector>

using namespace std;

struct Node{
    explicit Node(int v){
        val = v, left=nullptr, right= nullptr;
    };
    Node *left;
    Node *right;
    int val;
};

typedef vector<Node *> path;

void find_path_dfs(Node *cur_node, int loss, vector<Node *> &cur_path, vector<path> &path_list){
    cur_path.push_back(cur_node);
    if(cur_node->left==nullptr && cur_node->right==nullptr && loss==0){
        path_list.push_back(cur_path);
    }
    if(cur_node->left)
        find_path_dfs(cur_node->left, loss-cur_node->left->val, cur_path,path_list);
    if(cur_node->right)
        find_path_dfs(cur_node->right, loss-cur_node->right->val, cur_path, path_list);
    cur_path.pop_back();
}

vector<path> find_path(Node *root, int N){
    vector<path> all_path;
    vector<Node *> cur_path;
    find_path_dfs(root, N, cur_path, all_path);

    return all_path;
}

void release(Node *root){
    if(root== nullptr)
        return;
    release(root->left);
    release(root->right);
    delete root;
}

int main(){
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right= new Node(2);
    root->left->left = new Node(3);
    root->left->right= new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<path> all_path = find_path(root, 11);

    for(auto p:all_path){
        for(auto item:p){
            cout<<item->val<<" ";
        }
        cout<<endl;
    }

    release(root);

    return 0;
}
