/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the number of nodes in the tree.
*/

#include<climits>

TreeNode<int>* util(vector<int> &preOrder, int &preIndex, int startRange, int endRange){

    // If the preIndex is greater than the length of the array return NULL.
    if (preIndex >= preOrder.size()){
        return NULL;
    }

    int currNode = preOrder[preIndex];

    // If the current node lies inside the range then process the node.
    if (currNode > startRange && currNode < endRange){
        TreeNode<int>* root = new TreeNode<int>(currNode);

        // Increase the index by 1.
        preIndex += 1;

        // If left node exists process left.
        if (preIndex < preOrder.size()){
            root -> left = util(preOrder, preIndex, startRange, currNode);
        }
        // If right node exists process right.
        if (preIndex < preOrder.size()){
            root -> right = util(preOrder, preIndex, currNode , endRange);
        }

        // Return the root.
        return root;
    }

    // If node was not processed return NULL.
    return NULL;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    
    int preIndex = 0;

    // Return the util function.
    return util(preOrder, preIndex, INT_MIN, INT_MAX);
}
