/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where 'N' is the number of nodes in the given binary tree.
*/

int getMaxWidth(TreeNode<int> *root)
{
    //  Base case.
    if (root == NULL)
    {
        return 0;
    }

    //  For level order traversal.
    queue<TreeNode<int> *> q;
    q.push(root);

    int maxWidth = 0;
    
    //  Iterate over level by level.
    while (q.empty() == false)
    {
    
        //  Get the width of current level.
        int currWidth = q.size();
    
        //  Check, If the width of the current level is better than older?
        if (maxWidth < currWidth)
        {
            maxWidth = currWidth;
        }
    
        //  Push all the children of the root node which are at the current level.
        while (currWidth > 0)
        {
            //  Get the front of queue.
            TreeNode<int> *currNode = q.front();
            q.pop();
    
            //  Push left child of currNode if exist.
            if (currNode->left != NULL)
            {
                q.push(currNode->left);
            }
    
            //  Push right child of currNode if exist.
            if (currNode->right != NULL)
            {
                q.push(currNode->right);
            }

            currWidth = currWidth - 1;
        }
    }

    return maxWidth;
}
