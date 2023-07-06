 
#include<algorithm>
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> subsets;
    sort(arr.begin(), arr.end());

    // Trying all subsets.
    for (int mask = 0; mask < (1<<n); mask++){

        vector<int> cur;
        bool unique = true;
        for (int i = 0; i < n; i++){

            if (( mask & (1<<i) ) == 0){
                // Bit not set.
                continue;
            }

            if (i > 0 && arr[i] == arr[i-1] && (mask & (1<<(i-1))) == 0 ){
                unique = false;
            }

            if (unique == false){
                break;
            }
            
            // Inserting arr[i] to current subset.
            cur.push_back(arr[i]);
        }

        if(unique){
            subsets.push_back(cur);
        }
    }

    sort(subsets.begin(), subsets.end());
    return subsets;
}
