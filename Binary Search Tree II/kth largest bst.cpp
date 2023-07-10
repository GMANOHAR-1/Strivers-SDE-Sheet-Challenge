/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the total number of nodes of the BST.
*/

int revInorder(TreeNode<int>* root, int &visCount, int k)
{
	if (root == NULL)
	{
		return -1;
	}
	
	// Recurse over right subtree. 
	int right = revInorder(root -> right, visCount, k);
    
    if (right != -1)
    {
    	return right;
    }

	visCount++;

	if (visCount == k)
	{
		return root -> data;
	}

	// Recurse over left subtree.
	int left = revInorder(root -> left, visCount, k);
    
    return left;
}


int KthLargestNumber(TreeNode<int>* root, int k)
{
	int visCount = 0;

	return revInorder(root, visCount, k);
}
