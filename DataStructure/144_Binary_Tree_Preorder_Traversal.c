
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct TreeNode tree_t;

int TreeSize(const tree_t * self){
    return (self) ? TreeSize(self->left) + TreeSize(self->right) + 1 : 0;
}

int * _PreorderTraversal(const tree_t * self, int * curr){
    *curr++ = self->val;
    if(self->left)  { curr = _PreorderTraversal(self->left, curr); }
    if(self->right) { curr = _PreorderTraversal(self->right,curr); }
    return curr;
}

int * preorderTraversal(tree_t * root, int * returnSize){
    
    if(!root) return (int*)malloc((*returnSize = 0)*sizeof(int));
    
    *returnSize = TreeSize(root);
    int * ans = (int*)malloc((*returnSize)*sizeof(int));

    int * curr = ans;
    _PreorderTraversal(root, curr);
    return ans;
}