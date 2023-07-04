 
bool searchMatrix(vector<vector<int>>& mat, int target) {
    // Declare variables 'm' and 'n',
    // and initially assigned to 
    // number of rows and number of columns respectively.
    int m = mat.size(), n = mat[0].size();
    
    // Declare two variables 'start' and 'end'.
    int start = 0, end = m * n - 1;

    // Binary search.
    while (start <= end) {
        
        // Declare a variable 'mid'
        // which is assigned to the middle value of
        // 'start' and 'end'
        int mid = start + (end - start) / 2;
        
        // Get the value at 'mid'
        int val = mat[mid / n][mid % n];

        if (target < val) {
            // If current value is greater than 'target'
            // we will decrease 'end'
            end = mid - 1;
        } else if (target > val) {
            // If current value is smaller than 'target'
            // we will increase 'start'
            start = mid + 1;
        } else {
            return true;
        }
    }
    
    // If we didn't found anything,
    // we will return 'false'
    return false;
}
