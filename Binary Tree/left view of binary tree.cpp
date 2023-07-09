/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the number of nodes in the Binary Tree.
*/

//    Function for doing preorder traversal of a binary tree.
void preorderTraversal(TreeNode<int> *root, int level, int &maxLevel, vector<int> &leftView)
{
    if (root == NULL)
    {
        return;
    }

    //    If the current level is greater than the maxlevel then store the current node.
    if (level > maxLevel)
    {
        leftView.push_back(root->data);
        maxLevel = level;
    }

    //    Recur for the left subtree.
    preorderTraversal(root->left, level + 1, maxLevel, leftView);

    //    Recur for the right subtree.
    preorderTraversal(root->right, level + 1, maxLevel, leftView);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    
    //    For storing the left view of the binary tree.
    vector<int> leftView;

    int maxLevel = -1;

    //    Do a preorder traversal of the binary tree.
    preorderTraversal(root, 0, maxLevel, leftView);

    //    Return the left view of the binary tree.
    return leftView;
}
