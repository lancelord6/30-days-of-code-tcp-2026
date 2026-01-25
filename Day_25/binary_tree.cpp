void inorder(TreeNode* root, vector<int>& v) 
{
    if (root == NULL) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void preorder(TreeNode* root, vector<int>& v) 
{
    if (root == NULL) return;
    v.push_back(root->data);
    preorder(root->left, v);
    preorder(root->right, v);
}

void postorder(TreeNode* root, vector<int>& v) 
{
    if (root == NULL) return;
    postorder(root->left, v);
    postorder(root->right, v);
    v.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode* root) 
{
    vector<int> in, pre, post;
    inorder(root, in);
    preorder(root, pre);
    postorder(root, post);
    return {in, pre, post};
}