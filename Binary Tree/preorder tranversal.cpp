/*
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    where ‘N’ is the total number of nodes in the given binary tree.
*/

// Morris Traversal for preOrder.
vector<int> getPreOrderTraversal(TreeNode *root)
{

    // Create answer array to store traversal.
    vector<int> answer;

    // Base case.
    if (root == NULL)
    {
        return answer;
    }

    // 'PREDECESSOR' and 'CURRENT' will store predecessor and current nodes, respectively.
    TreeNode *current, *predecessor;

    // Initialize current node as 'ROOT'.
    current = root;

    // Run a loop until 'CURRENT' != NULL.
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // Add current node data to answer.
            answer.push_back(current->data);

            // Move to right child of current.
            current = current->right;
        }
        else
        {
            // Find predecessor of current node.
            predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            /*
                If the right child of predecessor already points to
                Current node then set right child as NULL and
                Move to right subtree of current.
            */
            if (predecessor->right == current)
            {
                predecessor->right = NULL;
                current = current->right;
            }

            else
            {
                // Add data of currrent node to answer.
                answer.push_back(current->data);

                // Set right subtree of predecessor as 'CURRENT'.
                predecessor->right = current;

                // Move to left subtree of 'CURRENT'.
                current = current->left;
            }
        }
    }

    return answer;
}
