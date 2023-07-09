/*
    Time Complexity  : O(N)
    Space Complexity : O(1)

    Where 'N' is the total number of nodes in the binary tree.
*/

#include <algorithm>

// Morris Traversal for inOrder.
vector<int> getInOrderTraversal(BinaryTreeNode<int> *root) {

    // Create answer array to store traversal.
    vector<int> answer;

    // Base case.
    if (root == NULL) {
        return answer;
    }

    // 'PREDECESSOR' and 'CURRENT' will store predecessor and current nodes, respectively.
    BinaryTreeNode<int> *current, *predecessor;

    // Initialize 'CURRENT' node as root.
    current = root;

    // Run a loop until 'CURRENT' != NULL.
    while (current != NULL) {
        if (current->left == NULL) {
            answer.push_back(current->data);
            current = current->right;
        }
        else {

            // Find the rightmost node on the left subtree of current.
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                /*
                    Make a link between predecessor and current node
                    So that we have a path to come back to current
                    When we have traversed the whole left subtree.
                */
                predecessor->right = current;
                current = current->left;
            }
            else {
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

// Morris Traversal for preOrder.
vector<int> getPreOrderTraversal(BinaryTreeNode<int> *root) {

    // Create answer array to store traversal.
    vector<int> answer;

    // Base case.
    if (root == NULL) {
        return answer;
    }

    // 'PREDECESSOR' and 'CURRENT' will store predecessor and current nodes, respectively.
    BinaryTreeNode<int> *current, *predecessor;

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
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            
            /*
                If the right child of predecessor already points to
                Current node then set right child as NULL and
                Move to right subtree of current.
            */
            if (predecessor->right == current) {
                predecessor->right = NULL;
                current = current->right;
            }

            else {
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

// Morris Traversal for postOrder.
vector<int> getPostOrderTraversal(BinaryTreeNode<int> *root) {

    // Create answer array to store traversal.
    vector<int> answer;

    // Base case.
    if (root == NULL) {
        return answer;
    }

    // 'PREDECESSOR' and 'CURRENT' will store predecessor and current nodes, respectively.
    BinaryTreeNode<int> *current, *predecessor;

    // Initialize current node as root.
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
            while (predecessor->left != NULL && predecessor->left != current) {
                predecessor = predecessor->left;
            }
            /*
                If the left child of predecessor already points to
                Current node then set left child as NULL and
                Move to left subtree of current.
            */
            if (predecessor->left == current) {
                predecessor->left = NULL;
                current = current->left;
            }

            else {
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

    // Return answer.
    return answer;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> result(3);

    // Call function to get inOrder Traversal.
    result[0] = getInOrderTraversal(root);

    // Call function to get preOrder Traversal.
    result[1] = getPreOrderTraversal(root);

    // Call function to get postOrder Traversal.
    result[2] = getPostOrderTraversal(root);

    // Return all 3 tree traversals.
    return result;
}
