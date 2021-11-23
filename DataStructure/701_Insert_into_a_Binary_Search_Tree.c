/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode tree_t;

/* First Trying Runtime = 40ms(win 20%), Memory = 22.6MB(win 93%). */
tree_t * _FindParent(tree_t * self, const int val){
    if(self->val > val && self->left ) return _FindParent(self->left,  val);
    if(self->val < val && self->right) return _FindParent(self->right, val);
    return self;
}

tree_t * insertIntoBST(tree_t * root, int val){
    
    if(root == NULL){
        root = (tree_t*)calloc(1, sizeof(tree_t));
        root->val = val;
        return root;
    }
    
    tree_t * parent = _FindParent(root, val);
    tree_t * add = (tree_t*)calloc(1, sizeof(tree_t));
    if(add){
        add->val = val;
        if(parent->val > add->val) parent->left = add;
        else parent->right = add;
    }
    return root;
}