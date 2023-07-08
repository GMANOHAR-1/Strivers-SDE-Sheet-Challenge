/*
    Time Complexity : O(N^2)
    Space Complexity : O(1)
    
    Where N is the length of the array.
*/

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans(n);

    // For every Element
    for (int i = 0; i < n; i++) {
        
        int next = -1;

        // Find its next greater element
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }

        ans[i] = next;
    }

    return ans;

}
