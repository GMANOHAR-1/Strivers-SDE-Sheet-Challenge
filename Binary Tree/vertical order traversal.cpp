/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    Where 'N' is the number of nodes in the given binary tree.
*/

#include <queue>

void getBreadth(TreeNode<int> *root, int hrDistance, int &minLeft, int &maxRight)
{
    if (root == NULL)
    {
        return;
    }

    // Recur for the left subtree.
    getBreadth(root->left, hrDistance - 1, minLeft, maxRight);

    // Recur for the right subtree.
    getBreadth(root->right, hrDistance + 1, minLeft, maxRight);

    // Update the 'minLeft' and 'maxRight' with the horizontal distance of the current node.
    minLeft = min(minLeft, hrDistance);
    maxRight = max(maxRight, hrDistance);
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    // Store the final result.
    vector<int> result;

    // Base case
    if (root == NULL)
    {
        return result;
    }

    //  To store the minimum and maximum horizontal distance.
    int minLeft = 0, maxRight = 0;

    //  Get the minimum and maximum horizontal distance.
    getBreadth(root, 0, minLeft, maxRight);

    // Create a map and store vertical order in map.
    vector<vector<int>> store(maxRight - minLeft + 1, vector<int>());

    // Initial horizontal distance.
    int hd = 0;
    int offset = abs(minLeft);

    // Every pair of queue contains node and horizontal distance with respect to the root node.
    queue<pair<TreeNode<int> *, int>> level;

    level.push(make_pair(root, hd));

    while (level.empty() == false)
    {
        // Pop element from the queue.
        pair<TreeNode<int> *, int> temp = level.front();
        level.pop();

        hd = temp.second;

        TreeNode<int> *node = temp.first;

        // Insert the value of current node in the vector of map.
        store[hd + offset].push_back(node->data);

        // For the left subtree, we pass the HD as the Horizontal distance of root minus 1.
        if (node->left != NULL)
        {
            level.push(make_pair(node->left, hd - 1));
        }

        // For the right subtree, we pass the HD as Horizontal Distance of root plus 1.
        if (node->right != NULL)
        {
            level.push(make_pair(node->right, hd + 1));
        }
    }

    for (int i = 0; i < store.size(); i++)
    {
        for (int j = 0; j < store[i].size(); ++j)
        {
            result.push_back(store[i][j]);
        }
    }

    // Return the vertical order traversal of the given binary tree.
    return result;
}
