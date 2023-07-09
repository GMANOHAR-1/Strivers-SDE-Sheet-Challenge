/*
    Time Complexity  : O(N)
    Space Complexity : O(N)

    Where N is the total number of nodes in the binary tree.
*/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {

    // Declare an empty array answer to store zigzag traversal
    vector<int> answer;

    // Base case
    if (root == NULL) {
        return answer;
    }

    // Declare an empty queue and push root to it
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    // Initialize reverseOrder as false
    bool reverseOrder = false;

    while (!q.empty()) {

        // Size of queue denotes number of nodes in current level
        int size = q.size();

        // declare an array of size to store elements of current level
        vector<int> currentLevelNodes;

        // Run a loop until nodes in the current level are greater than zero and add all its nodes data to currentLevelNodes
        for (int i = 0; i < size; i++) {

            // Pop front node from the queue
            BinaryTreeNode<int>* frontNode = q.front();
            q.pop();

            // Add data of node of current level node
            currentLevelNodes.push_back(frontNode->data);

            // Push left and right child of current level nodes to queue for next
            // Level iteration
            if (frontNode->left) {
                q.push(frontNode->left);
            }
            if (frontNode->right) {
                q.push(frontNode->right);
            }
        }

        // If reverse order is true then add data of nodes from left to right
        // Else add data of nodes in reverse order i.e. right to left
        for (int i = 0; i < size; i++)
        {
            if (reverseOrder == false) {
                answer.push_back(currentLevelNodes[i]);
            }
            else {
                answer.push_back(currentLevelNodes[size - i - 1]);
            }
        }

        //Change reverseOrder to false if it is true and vice-versa for the next level
        reverseOrder ^= 1;

    }

    // Return the answer
    return answer;
}
