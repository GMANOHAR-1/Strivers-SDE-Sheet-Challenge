/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(N)
    
    Where 'N' denotes the number of nodes in the BST.
*/

// Function to search the difference of current node's value and target 'k'. 
bool search(BinaryTreeNode<int> *root, BinaryTreeNode<int> *cur, int diff)
{
    if (root == NULL)
    {
        return false;
    }

    if (root -> data < diff)
    {
        return search(root -> right, cur, diff);
    }

    if (root -> data > diff)
    {
        return search(root -> left, cur, diff);
    }

    // This means that we have found the node having value equal to the diff.
    if (cur != root)
    {
        return true;
    }

    return false;
}

bool dfs(BinaryTreeNode<int> *root, int k, BinaryTreeNode<int> *cur)
{
    if (cur == NULL)
    {
        return false;
    }

    // Visit each node of BST and call the 'search' function.
    return (search(root, cur, k - cur->data) || dfs(root, k, cur -> left) || dfs(root, k, cur -> right));
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    return dfs(root, k, root);
}

