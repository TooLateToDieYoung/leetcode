typedef struct TreeNode tree_t;

bool hasPathSum(const tree_t * root, const int targetSum){
    if(root == NULL && targetSum != 0) return false;
    if(root != NULL){
        if(root->left == NULL && root->right == NULL && targetSum == root->val) return true;
        return hasPathSum(root->left,  targetSum - root->val) 
            || hasPathSum(root->right, targetSum - root->val);
    }
    return false;
}