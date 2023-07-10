/*
    Time complexity: O(N)
    Space complexity: O(1)
    
    Where 'N' is the number of nodes in a binary tree.
*/

void connectNodes(BinaryTreeNode<int> *root) {

    // Keep the address of the first node of the current level.
    BinaryTreeNode<int> *startNode = root;

    while(startNode != NULL) {

        BinaryTreeNode<int> *ptr = startNode;
        BinaryTreeNode<int> *previous = NULL;
        startNode = NULL;
        
        // Traversing over nodes of current level and populating 'next' pointer of nodes of next level.
        while(ptr != NULL) {

            if(ptr->left != NULL) {

                if(previous != NULL) {
                    previous->next = ptr->left;
                }

                // Update 'startNode' with first node of next level if not already done.
                if(startNode == NULL) {
                    startNode = ptr->left;
                }

                // Update previous pointer
                previous = ptr->left;
            }

            if(ptr->right != NULL) {

                if(previous != NULL) {
                    previous->next = ptr->right;
                }

                // Update 'startNode' with first node of next level if not already done.
                if(startNode == NULL) {
                    startNode = ptr->right;
                }

                // Update previous pointer.
                previous = ptr->right;
            }

            ptr = ptr->next;
        }
    }
}
