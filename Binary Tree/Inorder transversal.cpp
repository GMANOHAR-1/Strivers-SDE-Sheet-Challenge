/*
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    where ‘N’ is the total number of nodes in the given binary tree.
*/

// Morris Traversal for inOrder.
vector<int> getInOrderTraversal(TreeNode *root)
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
            answer.push_back(current->data);
            current = current->right;
        }
        else
        {

            // Find the rightmost node on the left subtree of current.
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL)
            {
                /*
                    Make a link between predecessor and current node
                    So that we have a path to come back to current
                    When we have traversed the whole left subtree.
                */
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                /*
                    If right node of predecessor is not NULL then it
                    Means we have traversed the whole left subtree.
                    So we unlink the connection between current and predecessor
                    And move to right node of current.
                */
                predecessor->right = NULL;
                answer.push_back(current->data);
                current = current->right;
            }
        }
    }

    return answer;
}
