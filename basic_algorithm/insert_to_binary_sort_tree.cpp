#include <iostream>
#include <list>

using namespace std;

struct Node{
    explicit Node(int v){
        val = v, left=nullptr, right= nullptr;
    };
    Node *left;
    Node *right;
    int val;
};

Node* insert_into_tree(Node *root, int val){
    if(root == nullptr)
        return new Node(val);
    if(val > root->val)
        root->right = insert_into_tree(root->right, val);
    else
        root->left = insert_into_tree(root->left, val);
    return root;
}

void release(Node *root){
    if(root== nullptr)
        return;
    release(root->left);
    release(root->right);
    delete root;
}

void layer_traverse_tree(Node *root){
    list<Node *> cur_layer = list<Node *>({root});
    list<Node *> nxt_layer = list<Node *>();
    while(!cur_layer.empty()){
        for(auto cur_node:cur_layer) {
            if (cur_node) {
                cout << cur_node->val << " ";
                nxt_layer.push_back(cur_node->left);
                nxt_layer.push_back(cur_node->right);
            }
        }
        cout<<endl;
        swap(cur_layer, nxt_layer);
        nxt_layer.clear();
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right= new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    insert_into_tree(root, 11);
    layer_traverse_tree(root);
    release(root);
    return 0;
}
