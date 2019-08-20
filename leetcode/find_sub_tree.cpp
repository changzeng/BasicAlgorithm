class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr)
            return false;
        if(s->val==t->val && isEqual(s, t)){
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isEqual(TreeNode* s, TreeNode *t){
        if(s==nullptr && t==nullptr) {
            return true;
        }else if(s==nullptr || t==nullptr){
            return false;
        }else{
            if(s->val == t->val){
                return isEqual(s->left, t->left) && isEqual(s->right, t->right);
            }
            return false;
        }
    }
};