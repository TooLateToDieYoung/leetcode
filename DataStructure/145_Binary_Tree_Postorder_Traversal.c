
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode tree_t;

size_t TreeSize(const tree_t * self){
    return (self) ? TreeSize(self->left) + TreeSize(self->right) + 1 : 0;
}

int * _PostorderTraversal(const tree_t * self, int * curr){
    if(self->left)  { curr = _PostorderTraversal(self->left, curr); }
    if(self->right) { curr = _PostorderTraversal(self->right,curr); }
    *curr++ = self->val;
    return curr;
}

int * postorderTraversal(tree_t * root, int* returnSize){
    if(!root) return (int*)malloc((*returnSize = 0)*sizeof(int));

    *returnSize = (int)TreeSize(root);
    int * ans = (int*)malloc((*returnSize)*sizeof(int));
    
    int * curr = ans;
    _PostorderTraversal(root, curr);
    return ans;
}