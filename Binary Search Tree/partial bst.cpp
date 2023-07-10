/*
    Time Complexity : O(N)
    Space Complexity : O(N).
    
    Where N denotes number of nodes in the binary tree
*/

bool helper(BinaryTreeNode<int>* root, BinaryTreeNode<int>*& prev) {
    // Traverse the tree in inorder fashion
    // Keep track of previous node
    if (root) {
        if (!helper(root->left, prev)) {  // Check left subtree
            return false;
        }

        if (prev != NULL && root->data < prev->data)  // Traversal not in ascending order.
        {
            return false;
        }

        prev = root;

        return helper(root->right, prev);  // Check right subtree
    }

    return true;
}

bool validateBST(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* prev = NULL;
    return (helper(root, prev));
}
