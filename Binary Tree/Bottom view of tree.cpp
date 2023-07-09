/* 
    Time complexity: O(N*log(N))
    Space complexity: O(N)

    Where ‘N’ is the number of nodes in the binary tree.
*/

vector<int> bottomView(BinaryTreeNode<int> *root) {
    // Horizontal distance of the root is initialised to 0.
    int horizontalDistance = 0;

    // Map with key as horzontal distance and value as the tree node.
    map<int, BinaryTreeNode<int> *> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    // Enqueue the root.
    q.push({root, 0});
    while (!q.empty()) {
        pair<BinaryTreeNode<int> *, int> p = q.front();
        q.pop();

        // Update the value for every horizontal distance.
        mp[p.second] = p.first;

        // If left child is present, push it.
        if (p.first->left != NULL) {
            q.push({p.first->left, p.second - 1});
        }
        // If right child is present, push it.
        if (p.first->right != NULL) {
            q.push({p.first->right, p.second + 1});
        }
    }
    vector<int> answer;

    // Store all final set of nodes in the answer vector.
    for (auto i = mp.begin(); i != mp.end(); i++) {
        answer.push_back(i->second->data);
    }
    return answer;
}
