/*
    Time Complexity - O(N)
    Space Complexity - O(1)

    Where N is the number of nodes in the Binary Tree.
*/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *currentNode = root;

    while (currentNode != NULL)
    {
        if (currentNode->left != NULL)
        {
            // Place the right subtree at its correct position (according to the linked list).
            // To do this, find the rightmost node present in the left subtree.
            TreeNode<int> *predecessor = currentNode->left;

            while (predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }

            // Make the right subtree of the current node as right child of "predecessor".
            predecessor->right = currentNode->right;

            // Make the left subtree of the current node as the new right subtree.
            currentNode->right = currentNode->left;

            currentNode->left = NULL;
        }

        // Set the right child of the node as the current node.
        currentNode = currentNode->right;
    }

    return root;
}
