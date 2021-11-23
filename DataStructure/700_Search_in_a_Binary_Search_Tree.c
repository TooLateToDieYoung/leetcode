
typedef struct TreeNode tree_t;

/* First Trying Runtime = 15ms, Memory = 15.5MB. */
tree_t * searchBST(const tree_t * root, const int val){
    if(root == NULL) return root;
    if(root->val == val) return root;
    
    tree_t * temp;
    temp = searchBST(root->left,  val);
    if(temp != NULL) return temp;
    temp = searchBST(root->right, val);
    if(temp != NULL) return temp;
    
    return NULL;
}

/* Second Trying Runtime = 16ms, Memory = 15.4MB. */
tree_t * searchBST(const tree_t * root, const int val){
    
    if(root == NULL) return root;
    if(root->val == val) return root;
    tree_t * temp;
    
    if(root->val > val) temp = searchBST(root->left, val);
    else temp = searchBST(root->right, val);
    
    if(temp != NULL) return temp;
    else return NULL;
}

/* Second Trying Runtime = 28ms, Memory = 15.4MB. */
tree_t * searchBST(const tree_t * root, const int val){
    if(!root || root->val == val) return root;
    return (root->val > val) ? searchBST(root->left, val) : searchBST(root->right, val);
}