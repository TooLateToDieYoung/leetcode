
typedef struct TreeNode tree_t;

// if we want to check for "left path" or "right path", but it's nullptr.
// Then the current node is parent who being inserted into its rear.
tree_t * _FindParent(tree_t * self, const int val){
    if(self->val > val && self->left ) return _FindParent(self->left,  val);
    if(self->val < val && self->right) return _FindParent(self->right, val);
    return self; 
}

tree_t * insertIntoBST(tree_t * root, int val){
    
	// Make sure that the first node has a value.
    if(root == NULL){
        root = (tree_t*)calloc(1, sizeof(tree_t));
        root->val = val;
        return root;
    }
    
	// Looking for the node that new data add in its rear.
    tree_t * parent = _FindParent(root, val);
    tree_t * add = (tree_t*)calloc(1, sizeof(tree_t));
	
	// Just assign data and add in trrreeeeeee.
    if(add){
        add->val = val;
        if(parent->val > add->val) parent->left = add;
        else parent->right = add;
    }
    return root;
}