/*
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    where ‘N’ is the total number of nodes in the given binary tree.
*/

// Morris Traversal for inOrder.
vector<int> getPostOrderTraversal(TreeNode *root)
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
        // Check if right subtree of node is NULL instead of left.
        if (current->right == NULL)
        {
            // Add current node data to 'ANSWER'.
            answer.push_back(current->data);

            // Move to left child of current.
            current = current->left;
        }
        else
        {
            // Find predecessor.
            predecessor = current->right;
            while (predecessor->left != NULL && predecessor->left != current)
            {
                predecessor = predecessor->left;
            }
            /*
                If the left child of predecessor already points to
                Current node then set left child as NULL and
                Move to left subtree of current.
            */
            if (predecessor->left == current)
            {
                predecessor->left = NULL;
                current = current->left;
            }

            else
            {
                // Add data of currrent node to answer.
                answer.push_back(current->data);

                // Set right subtree of predecessor as current.
                predecessor->left = current;

                // Move to right subtree of current.
                current = current->right;
            }
        }
    }

    // Reverse all elements of 'ANSWER' array.
    reverse(answer.begin(), answer.end());

    return answer;
}
