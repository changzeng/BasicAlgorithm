/*
给定一个二叉树，原地将它展开为链表。
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        merge(root);
    }

    TreeNode *merge(TreeNode *root){
        if(root==nullptr)
            return nullptr;
        TreeNode *left=merge(root->left);
        TreeNode *right=merge(root->right);
        if(root->left){
            if(root->right) {
                TreeNode *tmp = root->right;
                root->right = root->left;
                root->left = nullptr;
                left->right = tmp;
                return right;
            }else{
                root->right=root->left;
                root->left= nullptr;
                return left;
            }
        }else{
            if(root->right){
                return right;
            }else{
                return root;
            }
        }
    }
};