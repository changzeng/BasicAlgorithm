#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    explicit Node(char _val):val(_val), left(nullptr), right(nullptr){};
    Node *left;
    Node *right;
    char val;
};

Node *construct_tree(string &str, int &ind){
    if(str.empty() || ind >= str.size())
        return nullptr;
    Node *root = new Node(str[ind]);
    ind++;
    if(ind < str.size() && str[ind] == '('){
        ind++;
        root->left = construct_tree(str, ind);
        ind++;
        if(str[ind]!=')')
            root->right = construct_tree(str, ind);
        ind++;
    }
    return root;
}

void layer_traverse(Node *tree){
    vector<Node *> cur_layer({tree}), nxt_layer;
    while(!cur_layer.empty()){
        for(const auto node : cur_layer){
            if(node){
                cout<<node->val<<" ";
                nxt_layer.push_back(node->left);
                nxt_layer.push_back(node->right);
            }
        }
        cout<<endl;
        cur_layer.clear();
        swap(cur_layer, nxt_layer);
    }
}

void release(Node *root){
    if(!root)
        return;
    release(root->left);
    release(root->right);
    delete root;
}

int main(){
    int ind=0;
    // string str="a(a(b,d),c(e,f))";
    string str="a(b,)";
    Node *tree = construct_tree(str, ind);
    layer_traverse(tree);
    release(tree);

    return 0;
}
