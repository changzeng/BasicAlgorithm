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

void s_traverse_vec(Node *root){
    int layer=0;
    vector<Node *> cur_layer({root}), nxt_layer;
    while(!cur_layer.empty()){
        for(int i=(int)cur_layer.size()-1; i>=0; i--){
            if(cur_layer[i]) {
                cout<<cur_layer[i]->val<<" ";
                if(layer % 2 == 0) {
                    nxt_layer.push_back(cur_layer[i]->right);
                    nxt_layer.push_back(cur_layer[i]->left);
                }else{
                    nxt_layer.push_back(cur_layer[i]->left);
                    nxt_layer.push_back(cur_layer[i]->right);
                }
            }
        }
        layer++;
        cur_layer.swap(nxt_layer);
        nxt_layer.clear();
    }
    cout<<endl;
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
    s_traverse_vec(root);
    return 0;
}