/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the total number of nodes of the BST.
*/


TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	while (root != NULL)
	{
		if (root -> data < P -> data && root -> data < Q -> data)
		{
			root = root -> right;
		}
		else if (root -> data > P -> data && root -> data > Q -> data)
		{
			root = root -> left;
		}
		else
		{
			return root;
		}
	}
}
