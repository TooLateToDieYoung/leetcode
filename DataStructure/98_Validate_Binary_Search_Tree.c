
typedef struct TreeNode tree_t;

// For all nodes on the parent's left, the parent node is always the largest
bool isMax(const tree_t * const self, const int max){
    if(self == NULL) return true;
    if(self->val >= max) return false;
    return isMax(self->right, max);
}

// For all nodes on the parent's right, the parent node is always the largest
bool isMin(const tree_t * const self, const int min){
    if(self == NULL) return true;
    if(self->val <= min) return false;
    return isMin(self->left, min);
}

bool isValidBST(const tree_t * const root){
    if(root == NULL) return true;
    return isMax(root->left,  root->val) // Make sure for max rule.
        && isMin(root->right, root->val) // Make sure for min rule.
        && isValidBST(root->left )       // Check the left  subTree
        && isValidBST(root->right);      // Check the right subTree
}