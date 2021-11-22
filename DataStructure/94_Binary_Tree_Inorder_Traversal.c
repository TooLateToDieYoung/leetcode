/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode tree_t;

int TreeSize(const tree_t * self){
    return (self) ? TreeSize(self->left) + TreeSize(self->right) + 1 : 0;
}

int * _InorderTraversal(tree_t * self, int * curr){
    if(self->left)  { curr = _InorderTraversal(self->left,  curr); }
    *curr++ = self->val;
    if(self->right) { curr = _InorderTraversal(self->right, curr); }
    return curr;
}

int * inorderTraversal(tree_t * root, int * returnSize){
    if(!root) return (int*)malloc((*returnSize = 0)*sizeof(int));
    
    *returnSize = TreeSize(root);
    int * ans = (int*)malloc((*returnSize)*sizeof(int));

    int * curr = ans;
    _InorderTraversal(root, curr);
    return ans;
}
