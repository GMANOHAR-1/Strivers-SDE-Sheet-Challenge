 /*
    Time Complexity : O(N)
    Space Complexity : O(N)
	
    Where 'N' is the number of nodes in the given binary tree.
*/

//    Returns the LCA of ‘X’ and ‘Y’ or return -1 if it does not exist.
int findLCA(TreeNode<int> *root, int x, int y)
{

	if (root == NULL)
	{
		//    LCA can't exist in an empty tree.
		return -1;
	}
	else if (root->data == x || root->data == y)
	{
		//   The root node itself will be the LCA.
		return root->data;
	}
	else
	{
		//    Recur to find the LCA in the left subtree.
		int leftLCA = findLCA(root->left, x, y);

		//    Recur to find the LCA in the right subtree.
		int rightLCA = findLCA(root->right, x, y);

		if (leftLCA != -1 && rightLCA != -1)
		{
			//    The root must be the LCA since both ‘X’ and ‘Y’ are present in two different subtrees.
			return root->data;
		}
		else if (leftLCA != -1)
		{
			//    LCA exists in the left subtree.
			return leftLCA;
		}
		else
		{
			//    LCA exists in the right subtree.
			return rightLCA;
		}
	}
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return findLCA(root, x, y);
} 
