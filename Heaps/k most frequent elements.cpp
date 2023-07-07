/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the size of the input array.
*/

#include<map>
#include<algorithm>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int, int> mp;

    // Build map where the key is element
    // and value is how often this element appears in 'ARR'.
    for (int ele : arr) {

        mp[ele]++;
    }

    vector<int> bucket[n+1];

    for (auto x : mp) {

        int freq = x.second;

        // Add in correct bucket.
        bucket[freq].push_back(x.first);
    }

    vector<int> ans(k);
    int cur = 0;

    // Add 'K' elements to answer array starting from the rightmost bucket.
    for (int i = n; i > 0 && k > 0; i--) {

        if (bucket[i].size() == 0) {
            continue;
        }

        for (int num : bucket[i]) {

            ans[cur++] = num;
            k--;
            if(k == 0){
                break;
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
