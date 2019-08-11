#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node{
    explicit Node(int _val){
        val=_val; left= nullptr; right= nullptr; flag=false;
    };
    Node *left;
    Node *right;
    int val;
    bool flag;
};

int dfs_search(Node *root){
    if(!root)
        return 0;
    return max(dfs_search(root->left), dfs_search(root->right)) + 1;
}

int bfs_search(Node *root){
    int max_layer=0;
    vector<Node *> cur_layer;
    vector<Node *> nxt_layer;
    if(root)
        cur_layer.push_back(root);
    while(!cur_layer.empty()){
        max_layer++;
        for(auto cur_node:cur_layer) {
            if(cur_node->left)
                nxt_layer.push_back(cur_node->left);
            if(cur_node->right)
                nxt_layer.push_back(cur_node->right);
        }
        cur_layer.clear();
        swap(cur_layer, nxt_layer);
    }
    return max_layer;
}

int suf_order_no_recursive(Node *root){
    stack<Node *> node_stack;
    int max_depth=0, cur_depth=0;
    Node *cur_node=root;
    while(!node_stack.empty() || cur_node){
        if(cur_node){
            node_stack.push(cur_node);
            cur_node=cur_node->left;
            cur_depth++;
            max_depth = max(max_depth, cur_depth);
        }else{
            cur_node=node_stack.top();
            node_stack.pop();
            if(cur_node->flag){
                cur_depth--;
                cur_node = nullptr;
            }else{
                cur_node->flag=true;
                node_stack.push(cur_node);
                cur_node=cur_node->right;
            }
        }
    }
    return max_depth;
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
    root->right->right->right->left = new Node(100);

    cout<<dfs_search(root)<<endl;
    cout<<bfs_search(root)<<endl;
    cout<<suf_order_no_recursive(root)<<endl;

    release(root);

    return 0;
}
