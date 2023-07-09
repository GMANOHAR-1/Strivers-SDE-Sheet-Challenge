/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where 'N' is the number of nodes in the given binary tree.
*/

#include <queue>

void getBreadth(TreeNode<int> *root, int hrDistance, int &minLeft, int &maxRight) {	
	// If root is null then return.
	if (root == NULL){
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

vector<int> getTopView(TreeNode<int> *root) {
	// For storing top view element
	vector<int> topView;

	// If root is null then return top view.
	if (root == NULL) {
		return topView;
	}

	// To store the minimum and maximum horizontal distance.
	int minLeft = 0, maxRight = 0;

	// Get the minimum and maximum horizontal distance.
	getBreadth(root, 0, minLeft, maxRight);

	// To store the nodes.
	vector<int> visited(maxRight - minLeft + 1, -1);

	// Offset value.
	int offset = abs(minLeft);

	// For iterating level by level.
	queue<pair<TreeNode<int> *, int>> level;

	// Append root to the level with 0 horizontal distance.
	level.push({root, 0});

	// Iterate untill level does not become empty.
	while (level.size() != 0) {
		// Get total number of node at current level.
		int levelSize = level.size();

		while (levelSize != 0){
			// Get front of the queue.
			pair<TreeNode<int> *, int> curr = level.front();
			level.pop();

			// Get the horizontal distance of curr node.
			int hrDistance = curr.second;

			// Get current node.
			TreeNode<int> *currNode = curr.first;

			// Check whether hDistance is visited or not. If not visited then only it will be seen by the top of the tree.
			if (visited[hrDistance + offset] == -1) {
				//  Make it visited.
				visited[hrDistance + offset] = currNode->val;
			}

			// Append left child if it exist with horizontal distance one less than currNode.
			if (currNode->left != NULL) {
				level.push({currNode->left, hrDistance - 1});
			}

			// Append right child if it exist with horizontal distance one more than currNode.
			if (currNode->right != NULL) {
				level.push({currNode->right, hrDistance + 1});
			}
			levelSize = levelSize - 1;
		}
	}

	// Now visited have the element which can be the view from the top of the tree.
	for (auto x : visited) {
		if (x != -1) {
			topView.push_back(x);
		}
	}
	// Return the answer sequence of nodes.
	return topView;
}
