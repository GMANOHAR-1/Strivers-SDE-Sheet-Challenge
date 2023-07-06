 

void subset(int i, int sum, vector<int> &num, vector<int> &ans)
{

    // Completely traverse the whole array, insert the 'sum' in the 'ans' vector.
    if (i == num.size())
    {
        ans.push_back(sum);
        return;
    }

    // Insert the element in the sum.
    subset(i + 1, sum + num[i], num, ans);
    // Don't take the element in the sum.
    subset(i + 1, sum, num, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // 'ans' vector contains all the subset sums.
    vector<int> ans;

    subset(0, 0, num, ans);
    // Sort the vector and finally return it.
    sort(ans.begin(), ans.end());
    return ans;
}
