 
const int max_num = 30;  // Maximum possible element in given array.

void backtrack(vector<int> &comb, int remain, int curr, vector<int> &counter, vector<vector<int>> &result) 
{
    if(remain == 0) 
    {
        // The current combination has required sum.
        result.push_back(comb);
        return;
    }
    
    if(curr > max_num) 
    {
        // There exist no element greater than max_num in given array.
        return;
    }
        
    while(counter[curr] > 0 && remain >= curr) 
    {
        // Append all occurrence of 'curr' in current combination.
        comb.push_back(curr);
        counter[curr]--;
        remain -= curr;
    }
    
    // Try to find valid combinations with different groups of 'curr'.   
    while(comb.size() > 0 && comb.back() == curr) 
    {
        backtrack(comb, remain, curr+1, counter, result);
        comb.pop_back();
        remain += curr;
        counter[curr]++;
    }
        
    // Find valid combination without 'curr'. 
    backtrack(comb, remain, curr+1, counter, result);
}
    
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) 
{
    // Find frequency of each unique element.
    vector<int> counter(max_num+1);
        
    for(int i = 0; i < n; i++) 
    {
        counter[arr[i]]++;
    }
    
    vector<vector<int>> result;
    vector<int> comb;
        
    // Recursively find all possible combinations.
    backtrack(comb, target, 1, counter, result);
    
    return result;
}
